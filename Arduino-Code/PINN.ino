const long BAUD_RATE = 115200;

const int pwmPins[12] = {
  2, 3,
  4, 5,
  10, 11,
  12, 13,
  8, 9,
  6, 7
};

const int potPins[6] = {
  A0, A5, A4, A3, A2, A1
};

int pwmCmd[12] = {0};
int potADC[6] = {0};

char rxBuffer[120];
byte rxIndex = 0;

unsigned long lastCommandTime = 0;
unsigned long lastSendTime = 0;

const unsigned long timeout_ms = 200;
const unsigned long sendPeriod_ms = 50;   // send feedback every 10 ms

void setup() {
  Serial.begin(BAUD_RATE);

  for (int i = 0; i < 12; i++) {
    pinMode(pwmPins[i], OUTPUT);
    analogWrite(pwmPins[i], 0);
  }

  pinMode(22, OUTPUT);
  digitalWrite(22, LOW);

  lastCommandTime = millis();
  lastSendTime = millis();
}

void loop() {
  readSerialFromPC();

  safetyStopIfNoCommand();
  applyPWM();

}

void readSerialFromPC() {
  while (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '\r') {
      continue;
    }

    if (c == '\n') {
      rxBuffer[rxIndex] = '\0';
      parsePWMCommand(rxBuffer);
      rxIndex = 0;
    } 
    else {
      if (rxIndex < sizeof(rxBuffer) - 1) {
        rxBuffer[rxIndex++] = c;
      } 
      else {
        rxIndex = 0;
      }
    }
  }
}

void parsePWMCommand(char *line) {
  int v[12];

  int n = sscanf(line,
    "U,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
    &v[0], &v[1], &v[2], &v[3],
    &v[4], &v[5], &v[6], &v[7],
    &v[8], &v[9], &v[10], &v[11]);

  if (n == 12) {
    for (int i = 0; i < 12; i++) {
      pwmCmd[i] = constrain(v[i], 0, 255);
    }

    lastCommandTime = millis();
    applyPWM();

    // DO NOT send feedback here if you want fixed 50 ms feedback
    sendPotentiometersToPC();

    digitalWrite(22, !digitalRead(22));
  }
}

void applyPWM() {
  for (int i = 0; i < 12; i++) {
    analogWrite(pwmPins[i], pwmCmd[i]);
  }
}

void safetyStopIfNoCommand() {
  if (millis() - lastCommandTime > timeout_ms) {
    for (int i = 0; i < 12; i++) {
      pwmCmd[i] = 0;
    }
  }
}

void sendPotentiometersToPC() {
  for (int i = 0; i < 6; i++) {
    potADC[i] = analogRead(potPins[i]);
  }

  Serial.print("P,");

  for (int i = 0; i < 6; i++) {
    Serial.print(potADC[i]);
    Serial.print(",");
  }

  Serial.print(millis());   // timestamp at the end
  Serial.println();
}
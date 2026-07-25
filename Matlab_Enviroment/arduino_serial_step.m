function y = arduino_serial_step(pwm)
% PC-side serial step for Simulink Interpreted MATLAB Function block
% Input:
%   pwm = 12x1 PWM vector
%
% Output y = 20x1:
%   y(1:6)    = ADC feedback
%   y(7:18)   = PWM debug
%   y(19)     = valid flag
%   y(20)     = nbytes before reading

persistent s lastADC lastPWM initialized

PORT = "COM3";
BAUD = 115200;

if isempty(initialized)
    s = serialport(PORT, BAUD, "Timeout", 0.2);
    configureTerminator(s, "LF");

    pause(4);       % Arduino reset after COM opens
    flush(s);
    pause(0.5);

    lastADC = zeros(6,1);
    lastPWM = zeros(12,1);
    initialized = true;
end

valid = 0;
nbytes = double(s.NumBytesAvailable);

% Read all available feedback and keep latest valid P packet
while s.NumBytesAvailable > 0
    try
        line = readline(s);
        vals = sscanf(char(line), 'P,%f,%f,%f,%f,%f,%f');

        if numel(vals) == 6
            lastADC = vals(:);
            valid = 1;
        end
    catch
        break;
    end
end

% If no complete line was ready, wait for one line
if valid == 0
    try
        line = readline(s);
        vals = sscanf(char(line), 'P,%f,%f,%f,%f,%f,%f');

        if numel(vals) == 6
            lastADC = vals(:);
            valid = 1;
        end
    catch
        % keep previous ADC
    end
end

% Prepare PWM
pwm = double(pwm(:));

if numel(pwm) < 12
    pwm = [pwm; zeros(12-numel(pwm),1)];
end

pwm = pwm(1:12);
pwm = round(pwm);
pwm = min(max(pwm, 0), 255);

lastPWM = pwm;

msg = sprintf('U,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d', ...
    pwm(1), pwm(2), pwm(3), pwm(4), ...
    pwm(5), pwm(6), pwm(7), pwm(8), ...
    pwm(9), pwm(10), pwm(11), pwm(12));

writeline(s, msg);

y = zeros(20,1);
y(1:6) = lastADC;
y(7:18) = lastPWM;
y(19) = valid;
y(20) = nbytes;
end
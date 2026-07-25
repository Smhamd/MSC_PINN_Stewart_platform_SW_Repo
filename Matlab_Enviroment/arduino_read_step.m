function y = arduino_read_step(~)
% Read Arduino potentiometer feedback.
% Expected Arduino line:
% P,A0,A5,A4,A3,A2,A1,time
%
% Output y = 10x1:
% y(1:6)  = ADC feedback
% y(7)    = valid/alive flag
% y(8)    = nbytes
% y(9)    = Arduino timestamp millis()
% y(10)   = dt between Arduino packets in ms

persistent lastADC rxBuffer lastGoodTime initialized lastTime lastDt

s = arduino_open_serial();

if isempty(initialized)
    lastADC = zeros(6,1);
    rxBuffer = '';
    lastGoodTime = tic;
    lastTime = 0;
    lastDt = 0;
    initialized = true;
end

nbytes = 0;

try
    nbytes = double(s.NumBytesAvailable);

    if nbytes > 0
        data = read(s, nbytes, "uint8");
        rxBuffer = [rxBuffer, char(data(:).')];

        lfIdx = find(rxBuffer == char(10));
        startIdx = 1;

        for k = 1:numel(lfIdx)
            oneLine = rxBuffer(startIdx:lfIdx(k)-1);
            oneLine = strtrim(oneLine);

            % Parse 7 values:
            % 6 ADC values + timestamp at the end
            vals = sscanf(oneLine, 'P,%f,%f,%f,%f,%f,%f,%f');

            if numel(vals) >= 6
                lastADC = vals(1:6);
                lastGoodTime = tic;

                if numel(vals) >= 7
                    currentTime = vals(7);

                    if lastTime > 0
                        lastDt = currentTime - lastTime;
                    end

                    lastTime = currentTime;
                end
            end

            startIdx = lfIdx(k) + 1;
        end

        if startIdx <= length(rxBuffer)
            rxBuffer = rxBuffer(startIdx:end);
        else
            rxBuffer = '';
        end
    end

catch
    nbytes = -1;
end

feedbackTimeout = 0.5;   % seconds

if toc(lastGoodTime) < feedbackTimeout
    valid = 1;
else
    valid = 0;
end

y = zeros(10,1);
y(1:6) = lastADC;
y(7) = valid;
y(8) = nbytes;
y(9) = lastTime;
y(10) = lastDt;

end
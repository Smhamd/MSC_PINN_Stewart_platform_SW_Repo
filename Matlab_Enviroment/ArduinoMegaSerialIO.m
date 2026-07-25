classdef ArduinoMegaSerialIO < matlab.System
    properties
        Port = "COM3";
        BaudRate = 115200;
    end

    properties(Access = private)
        s
        lastADC
        lastPWM
    end

    methods(Access = protected)

        function setupImpl(obj)
            obj.s = serialport(obj.Port, obj.BaudRate, "Timeout", 0.2);
            configureTerminator(obj.s, "LF");

            pause(4);      % Arduino reset delay
            flush(obj.s);
            pause(0.5);    % wait for new P messages

            obj.lastADC = zeros(6,1);
            obj.lastPWM = zeros(12,1);
        end

        function [adc, pwm_debug, valid, nbytes] = stepImpl(obj, pwm)

            valid = 0;
            nbytes = double(obj.s.NumBytesAvailable);

            % -------------------------------------------------
            % 1) Read all available Arduino feedback lines
            % -------------------------------------------------
            while obj.s.NumBytesAvailable > 0
                try
                    line = readline(obj.s);
                    vals = sscanf(char(line), 'P,%f,%f,%f,%f,%f,%f');

                    if numel(vals) == 6
                        obj.lastADC = vals(:);
                        valid = 1;
                    end
                catch
                    break;
                end
            end

            % If nothing was already available, wait for one fresh line
            if valid == 0
                try
                    line = readline(obj.s);
                    vals = sscanf(char(line), 'P,%f,%f,%f,%f,%f,%f');

                    if numel(vals) == 6
                        obj.lastADC = vals(:);
                        valid = 1;
                    end
                catch
                    % keep previous ADC
                end
            end

            % -------------------------------------------------
            % 2) Prepare PWM command
            % -------------------------------------------------
            pwm = double(pwm(:));

            if numel(pwm) < 12
                pwm = [pwm; zeros(12-numel(pwm),1)];
            end

            pwm = pwm(1:12);
            pwm = round(pwm);
            pwm = min(max(pwm, 0), 255);

            obj.lastPWM = pwm;

            msg = sprintf('U,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d', ...
                pwm(1), pwm(2), pwm(3), pwm(4), ...
                pwm(5), pwm(6), pwm(7), pwm(8), ...
                pwm(9), pwm(10), pwm(11), pwm(12));

            writeline(obj.s, msg);

            adc = obj.lastADC;
            pwm_debug = obj.lastPWM;
        end

        function releaseImpl(obj)
            if ~isempty(obj.s)
                flush(obj.s);
                obj.s = [];
            end
        end

        function resetImpl(obj)
            obj.lastADC = zeros(6,1);
            obj.lastPWM = zeros(12,1);
        end

        function [sz1, sz2, sz3, sz4] = getOutputSizeImpl(~)
            sz1 = [6 1];
            sz2 = [12 1];
            sz3 = [1 1];
            sz4 = [1 1];
        end

        function [dt1, dt2, dt3, dt4] = getOutputDataTypeImpl(~)
            dt1 = "double";
            dt2 = "double";
            dt3 = "double";
            dt4 = "double";
        end

        function [c1, c2, c3, c4] = isOutputComplexImpl(~)
            c1 = false;
            c2 = false;
            c3 = false;
            c4 = false;
        end

        function [f1, f2, f3, f4] = isOutputFixedSizeImpl(~)
            f1 = true;
            f2 = true;
            f3 = true;
            f4 = true;
        end
    end
end
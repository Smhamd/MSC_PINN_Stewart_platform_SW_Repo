function pwm_debug = arduino_write_step(pwm)
% Send PWM command to Arduino.
%
% Input pwm = 12x1:
% [pwm2 pwm3 pwm4 pwm5 pwm10 pwm11 pwm12 pwm13 pwm8 pwm9 pwm6 pwm7]
%
% Output pwm_debug = 12x1 PWM values actually sent.

s = arduino_open_serial();

pwm = double(pwm(:));

if numel(pwm) < 12
    pwm = [pwm; zeros(12-numel(pwm),1)];
end

pwm = pwm(1:12);
pwm = round(pwm);
pwm = min(max(pwm, 0), 255);

msg = sprintf('U,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d', ...
    pwm(1), pwm(2), pwm(3), pwm(4), ...
    pwm(5), pwm(6), pwm(7), pwm(8), ...
    pwm(9), pwm(10), pwm(11), pwm(12));

writeline(s, msg);

pwm_debug = pwm;
end
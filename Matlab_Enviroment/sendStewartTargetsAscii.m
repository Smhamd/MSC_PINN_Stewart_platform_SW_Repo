function sendStewartTargetsAscii(L_cmd_mm)

persistent s lastOpenTime

port = "COM3";
baud = 115200;

if isempty(s) || ~isvalid(s)
    s = serialport(port, baud);
    configureTerminator(s, "LF");
    flush(s);
    lastOpenTime = tic;
    pause(10.0);
end

if toc(lastOpenTime) < 5.0
    return;
end

L = reshape(double(L_cmd_mm), [1,6]);
L = min(max(L, 0), 90);

msg = strjoin(compose("%.3f", L), ",");

write(s, uint8([char(msg) 10]), "uint8");

end
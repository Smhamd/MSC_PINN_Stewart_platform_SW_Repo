function s = arduino_open_serial()
% Shared Arduino serial object.

persistent sp initialized

PORT = "COM3";
BAUD = 115200;

needOpen = false;

if isempty(initialized) || isempty(sp)
    needOpen = true;
else
    try
        tmp = sp.NumBytesAvailable; %#ok<NASGU>
    catch
        needOpen = true;
    end
end

if needOpen
    try
        old = serialportfind("Port", PORT);
        if ~isempty(old)
            delete(old);
        end
    catch
    end

    sp = serialport(PORT, BAUD, "Timeout", 0.05);
    configureTerminator(sp, "LF");

    pause(4);      % Arduino reset
    flush(sp);
    pause(0.2);

    initialized = true;
    disp("Arduino serial opened.")
end

s = sp;
end
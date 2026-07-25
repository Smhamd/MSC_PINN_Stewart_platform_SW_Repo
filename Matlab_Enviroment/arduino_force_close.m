function arduino_force_close()
% Safe close for Simulink StopFcn / manual use.
% Do NOT call set_param stop inside this function.

disp("Closing Arduino serial...")

try
    objs = serialportfind;
    if ~isempty(objs)
        delete(objs);
    end
catch
end

try
    evalin('base','clear s sp');
catch
end

clear arduino_open_serial
clear arduino_read_step
clear arduino_write_step

pause(0.5);

disp("Arduino serial closed and persistent states cleared.")
end
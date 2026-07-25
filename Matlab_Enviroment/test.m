clear; clc;

%% ==============================
% 1) Serial setup
% ===============================

port = "COM3";
baud = 115200;

try
    delete(serialportfindall);
catch
end

s = serialport(port, baud);
configureTerminator(s, "LF");

% You said this works better on your system
s.Timeout = 10;

pause(5);          % Arduino reset delay
flush(s, "input");

fprintf("Connected to Arduino on %s\n", port);

%% ==============================
% 2) Choose PINN function
% ===============================

if exist("true_pinn_fixedik_command", "file") == 2
    pinnFcn = @true_pinn_fixedik_command;
    disp("Using true_pinn_fixedik_command");
elseif exist("true_pinn_stewart_command", "file") == 2
    pinnFcn = @true_pinn_stewart_command;
    disp("Using true_pinn_stewart_command");
else
    error("Cannot find exported PINN function. Put true_pinn_fixedik_command.m or true_pinn_stewart_command.m in this folder.");
end

%% ==============================
% 3) Control settings
% ===============================

Ts = 0.05;          % 20 Hz
Ttotal = 60;        % seconds

% Start safe:
% alpha = 0 means IK only, no correction.
% After this works, try alpha = 0.01, then 0.02.
alpha = 0.0;

% Safe home pose
Z0 = 323.5;         % mm
homePose = [0; 0; Z0; 0; 0; 0];  % X,Y,Z,roll,pitch,yaw

% Small test trajectory
AmpX = 10;          % mm, start small
freq = 0.03;        % Hz

% Length safety
minLen = 0;
maxLen = 90;

READ_REPLY = true;  % true for debug, false for final faster control

%% ==============================
% 4) First send home for 5 seconds
% ===============================

disp("Sending home pose...");

for k = 1:round(5/Ts)
    u = homePose;

    [L_cmd, dL_pred, L_phys] = pinnFcn(u, alpha);

    L_cmd = reshape(double(L_cmd), [1,6]);
    L_cmd = min(max(L_cmd, minLen), maxLen);

    sendLengths(s, L_cmd, READ_REPLY);

    pause(Ts);
end

%% ==============================
% 5) Run trajectory
% ===============================

disp("Running PINN trajectory...");

tStart = tic;

while toc(tStart) < Ttotal
    t = toc(tStart);

    % Desired pose
    X = AmpX * sin(2*pi*freq*t);
    Y = 0;
    Z = Z0;

    roll  = 0;
    pitch = 0;
    yaw   = 0;

    u = [X; Y; Z; roll; pitch; yaw];

    % PINN / IK command
    [L_cmd, dL_pred, L_phys] = pinnFcn(u, alpha);

    L_cmd = reshape(double(L_cmd), [1,6]);
    L_cmd = min(max(L_cmd, minLen), maxLen);

    sendLengths(s, L_cmd, READ_REPLY);

    fprintf("t=%.2f | Lcmd = %.2f %.2f %.2f %.2f %.2f %.2f\n", ...
        t, L_cmd(1), L_cmd(2), L_cmd(3), L_cmd(4), L_cmd(5), L_cmd(6));

    pause(Ts);
end

%% ==============================
% 6) Stop / hold home
% ===============================

disp("Returning to home...");

for k = 1:round(3/Ts)
    u = homePose;

    [L_cmd, dL_pred, L_phys] = pinnFcn(u, alpha);

    L_cmd = reshape(double(L_cmd), [1,6]);
    L_cmd = min(max(L_cmd, minLen), maxLen);

    sendLengths(s, L_cmd, READ_REPLY);

    pause(Ts);
end

disp("Done.");

%% ==============================
% Local function
% ===============================

function sendLengths(s, L, readReply)
    msg = strjoin(compose("%.3f", L), ",");

    % Send ASCII CSV + LF
    write(s, uint8([char(msg) 10]), "uint8");

    if readReply
        try
            reply = readline(s);
            reply = strtrim(reply);

            % Only print OK/ERR lines
            if startsWith(reply, "OK") || startsWith(reply, "ERR")
                fprintf("Arduino: %s\n", reply);
            end
        catch
            % Ignore timeout during control
        end
    end
end
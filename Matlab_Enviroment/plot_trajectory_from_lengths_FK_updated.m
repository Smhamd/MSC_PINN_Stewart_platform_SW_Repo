%% Plot desired vs actual Stewart trajectory from actuator length data
% Data columns in out.T1_DP6_IL6_AL6_ER6:
% 1      time
% 2:7    desired pose [X Y Z Roll Pitch Yaw]
% 8:13   desired actuator extensions [mm]
% 14:19  actual actuator extensions [mm]
%
% This script calculates:
% 1) Desired XYZ path from desired lengths using FK
% 2) Actual XYZ path from actual lengths using FK
% 3) Real 3D path RMSE between desired path and actual path
% 4) Actuator-length RMSE/MAE/MAX and delay

clearvars -except out

A = out.T1_DP6_IL6_AL6_ER6;

%% ================= SETTINGS =================
startTime  = 100;     % start analysis after this time [s]
maxSamples = 1000;    % reduce if FK is slow

% Stewart geometry in mm
geom.Rb = 185;        % base radius [mm]
geom.Rp = 150;        % platform radius [mm]
geom.Z0 = 323.5;      % home height [mm]

% Angles from the working IK geometry
geom.baseAngles_deg = [25 49 145 169 265 289];
geom.platAngles_deg = [0 74 120 194 240 314];

% Logged actuator values are extensions from home, not full leg lengths.
geom.lengthIsExtensionFromHome = true;
geom.Lhome = home_leg_lengths(geom);

%% ================= EXTRACT AND FILTER DATA =================
t_all = A(:,1);

Pose_des_logged_all = A(:,2:7);   % [X Y Z Roll Pitch Yaw]
Ldes_all = A(:,8:13);             % desired actuator extensions [mm]
Lact_all = A(:,14:19);            % actual actuator extensions [mm]

idx = t_all >= startTime;
idx = idx & all(Lact_all ~= 0, 2);
idx = idx & all(isfinite(Pose_des_logged_all), 2);
idx = idx & all(isfinite(Ldes_all), 2);
idx = idx & all(isfinite(Lact_all), 2);

t_full = t_all(idx);
Pose_des_logged_full = Pose_des_logged_all(idx,:);
Ldes_full = Ldes_all(idx,:);
Lact_full = Lact_all(idx,:);

t_full = t_full - t_full(1);

%% ================= ACTUATOR LENGTH METRICS =================
leg_err = Ldes_full - Lact_full;

rmse_each = sqrt(mean(leg_err.^2, 1));
mae_each  = mean(abs(leg_err), 1);
max_error_each = max(abs(leg_err), [], 1);

%% ================= ACTUATOR DELAY =================
Ts_full = mean(diff(t_full));
delay_sec = zeros(1,6);

for i = 1:6
    xd = Ldes_full(:,i) - mean(Ldes_full(:,i));
    xa = Lact_full(:,i) - mean(Lact_full(:,i));

    [c,lags] = xcorr(xa, xd, 'coeff');
    [~,idxMax] = max(c);

    delay_sec(i) = lags(idxMax) * Ts_full;
end

metricsTable = table( ...
    (1:6).', ...
    rmse_each.', ...
    mae_each.', ...
    max_error_each.', ...
    delay_sec.', ...
    'VariableNames', {'Actuator','RMSE_mm','MAE_mm','MaxError_mm','Delay_s'} ...
);

fprintf('\n================ ACTUATOR LENGTH TRACKING ERROR ================\n');
disp(metricsTable)

%% ================= DOWNSAMPLE FOR FK SPEED =================
N0 = length(t_full);

if N0 > maxSamples
    id = round(linspace(1, N0, maxSamples));
else
    id = 1:N0;
end

t = t_full(id);
Pose_des_logged = Pose_des_logged_full(id,:);
Ldes = Ldes_full(id,:);
Lact = Lact_full(id,:);

N = length(t);

%% ================= FK FROM DESIRED AND ACTUAL LENGTHS =================
Pose_des_from_L = zeros(N,6);
Pose_act_from_L = zeros(N,6);

% Initial guesses
q_des_prev = Pose_des_logged(1,:);
q_act_prev = Pose_des_logged(1,:);

for k = 1:N
    % Desired pose reconstructed from desired actuator lengths
    q_des_prev = stewart_fk_from_lengths_fminsearch(Ldes(k,:), q_des_prev, geom);
    Pose_des_from_L(k,:) = q_des_prev;

    % Actual pose reconstructed from actual actuator lengths
    q_act_prev = stewart_fk_from_lengths_fminsearch(Lact(k,:), q_act_prev, geom);
    Pose_act_from_L(k,:) = q_act_prev;
end

%% ================= PATH ERROR: ACTUAL PATH VS DESIRED PATH =================
X_des = Pose_des_from_L(:,1);
Y_des = Pose_des_from_L(:,2);
Z_des = Pose_des_from_L(:,3);

X_act = Pose_act_from_L(:,1);
Y_act = Pose_act_from_L(:,2);
Z_act = Pose_act_from_L(:,3);

% Error in each Cartesian direction
err_X = X_des - X_act;
err_Y = Y_des - Y_act;
err_Z = Z_des - Z_act;

% 3D Euclidean path error at every sample
err_3D = sqrt(err_X.^2 + err_Y.^2 + err_Z.^2);

% RMSE per axis
RMSE_X = sqrt(mean(err_X.^2));
RMSE_Y = sqrt(mean(err_Y.^2));
RMSE_Z = sqrt(mean(err_Z.^2));

% Full 3D path error metrics
RMSE_path = sqrt(mean(err_3D.^2));
MAE_path  = mean(abs(err_3D));
MAX_path  = max(abs(err_3D));

pathErrorTable = table( ...
    RMSE_X, RMSE_Y, RMSE_Z, RMSE_path, MAE_path, MAX_path, ...
    'VariableNames', {'RMSE_X_mm','RMSE_Y_mm','RMSE_Z_mm','RMSE_3D_mm','MAE_3D_mm','MAX_3D_mm'} ...
);

fprintf('\n================ PATH ERROR: ACTUAL PATH VS DESIRED PATH ================\n');
disp(pathErrorTable)

fprintf('\nTrajectory position error from FK lengths:\n');
fprintf('RMSE = %.4f mm\n', RMSE_path);
fprintf('MAE  = %.4f mm\n', MAE_path);
fprintf('MAX  = %.4f mm\n', MAX_path);

%% ================= FIND MAX PATH ERROR SAMPLE =================
[~, maxIdx] = max(err_3D);

fprintf('\nMax path error occurs at:\n');
fprintf('t = %.4f s\n', t(maxIdx));
fprintf('err_X = %.4f mm, err_Y = %.4f mm, err_Z = %.4f mm\n', ...
    err_X(maxIdx), err_Y(maxIdx), err_Z(maxIdx));
fprintf('3D error = %.4f mm\n', err_3D(maxIdx));

%% ================= 3D TRAJECTORY PLOT =================
figure;
plot3(X_des, Y_des, Z_des, 'b--', 'LineWidth', 1.5);
hold on;
plot3(X_act, Y_act, Z_act, 'r', 'LineWidth', 1.5);
grid on;
axis equal;

xlabel('X [mm]');
ylabel('Y [mm]');
zlabel('Z [mm]');
legend('Desired from lengths','Actual from lengths');
title('Stewart Platform 3D Trajectory From Lengths');

%% ================= X-Z PLOT =================
figure;
plot(X_des, Z_des, 'b--', 'LineWidth', 1.5);
hold on;
plot(X_act, Z_act, 'r', 'LineWidth', 1.5);
grid on;
axis equal;

xlabel('X [mm]');
ylabel('Z [mm]');
legend('Desired from lengths','Actual from lengths');
title('X-Z Trajectory From Lengths');

%% ================= X-Y PLOT =================
figure;
plot(X_des, Y_des, 'b--', 'LineWidth', 1.5);
hold on;
plot(X_act, Y_act, 'r', 'LineWidth', 1.5);
grid on;
axis equal;

xlabel('X [mm]');
ylabel('Y [mm]');
legend('Desired from lengths','Actual from lengths');
title('X-Y Trajectory From Lengths');

%% ================= XYZ VS TIME =================
figure;
tiledlayout(3,1);

nexttile;
plot(t, X_des, 'b--', 'LineWidth', 1.2);
hold on;
plot(t, X_act, 'r', 'LineWidth', 1.2);
grid on;
ylabel('X [mm]');
legend('Desired','Actual');
title('X tracking');

nexttile;
plot(t, Y_des, 'b--', 'LineWidth', 1.2);
hold on;
plot(t, Y_act, 'r', 'LineWidth', 1.2);
grid on;
ylabel('Y [mm]');
legend('Desired','Actual');
title('Y tracking');

nexttile;
plot(t, Z_des, 'b--', 'LineWidth', 1.2);
hold on;
plot(t, Z_act, 'r', 'LineWidth', 1.2);
grid on;
xlabel('Time [s]');
ylabel('Z [mm]');
legend('Desired','Actual');
title('Z tracking');

%% ================= 3D PATH ERROR PLOT =================
figure;
plot(t, err_3D, 'LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('3D path error [mm]');
title('Actual Path vs Desired Path Error');

%% ================= XYZ ERROR SEPARATELY =================
figure;
tiledlayout(3,1);

nexttile;
plot(t, err_X, 'LineWidth', 1.2);
grid on;
ylabel('X error [mm]');
title('X path error');

nexttile;
plot(t, err_Y, 'LineWidth', 1.2);
grid on;
ylabel('Y error [mm]');
title('Y path error');

nexttile;
plot(t, err_Z, 'LineWidth', 1.2);
grid on;
xlabel('Time [s]');
ylabel('Z error [mm]');
title('Z path error');

%% ================= ACTUATOR TRACKING PLOTS =================
figure;
tiledlayout(3,2);

for i = 1:6
    nexttile;
    plot(t_full, Ldes_full(:,i), '--', 'LineWidth', 1.2);
    hold on;
    plot(t_full, Lact_full(:,i), 'LineWidth', 1.2);
    grid on;
    xlabel('Time [s]');
    ylabel('Length [mm]');
    legend(['L' num2str(i) ' desired'], ['L' num2str(i) ' actual']);
    title(['L' num2str(i) ' tracking']);
end

sgtitle(['Actuator Tracking From t = ' num2str(startTime) ' s']);

%% ================= ACTUATOR ERROR PLOT =================
figure;
for i = 1:6
    plot(t_full, leg_err(:,i), 'LineWidth', 1.1);
    hold on;
end

grid on;
xlabel('Time [s]');
ylabel('Length error [mm]');
legend('L1 error','L2 error','L3 error','L4 error','L5 error','L6 error');
title(['Actuator Tracking Error From t = ' num2str(startTime) ' s']);

%% ================= SAVE RESULTS TO WORKSPACE =================
results_FK_path = struct();
results_FK_path.pathErrorTable = pathErrorTable;
results_FK_path.metricsTable = metricsTable;
results_FK_path.t = t;
results_FK_path.Pose_des_from_L = Pose_des_from_L;
results_FK_path.Pose_act_from_L = Pose_act_from_L;
results_FK_path.err_X = err_X;
results_FK_path.err_Y = err_Y;
results_FK_path.err_Z = err_Z;
results_FK_path.err_3D = err_3D;
results_FK_path.RMSE_path = RMSE_path;
results_FK_path.MAE_path = MAE_path;
results_FK_path.MAX_path = MAX_path;

assignin('base', 'results_FK_path', results_FK_path);

%% ========================================================================
function q = stewart_fk_from_lengths_fminsearch(L_measured, q0, geom)
% q = [X Y Z Roll Pitch Yaw]
% L_measured are actuator extensions in mm.

L_measured = double(reshape(L_measured, [1,6]));
q0 = double(reshape(q0, [1,6]));

% Scale variables so rotation and translation are balanced
scale = [50 50 50 0.05 0.05 0.05];

z0 = q0 ./ scale;

costFun = @(z) fk_cost(z .* scale, L_measured, geom);

opts = optimset( ...
    'Display','off', ...
    'MaxIter',200, ...
    'MaxFunEvals',800, ...
    'TolX',1e-7, ...
    'TolFun',1e-7);

z = fminsearch(costFun, z0, opts);

q = z .* scale;
q = reshape(q, [1,6]);
end

%% ========================================================================
function cost = fk_cost(q, L_measured, geom)
L_pred = stewart_lengths_from_pose(q, geom);

e = L_pred - L_measured;

cost = sum(e.^2);

% Soft penalty to avoid impossible jumps
if q(3) < 150 || q(3) > 500
    cost = cost + 1e6;
end

if abs(q(4)) > 0.5 || abs(q(5)) > 0.5 || abs(q(6)) > 0.5
    cost = cost + 1e6;
end
end

%% ========================================================================
function Lout = stewart_lengths_from_pose(q, geom)
% Compute actuator extension or total leg length from pose.

X = q(1);
Y = q(2);
Z = q(3);
Roll  = q(4);
Pitch = q(5);
Yaw   = q(6);

B = platform_points(geom.Rb, geom.baseAngles_deg);
P = platform_points(geom.Rp, geom.platAngles_deg);

R = rotz_mat(Yaw) * roty_mat(Pitch) * rotx_mat(Roll);

pos = [X; Y; Z];

Ltotal = zeros(1,6);

for i = 1:6
    Pi_global = pos + R * P(:,i);
    vec = Pi_global - B(:,i);
    Ltotal(i) = norm(vec);
end

if geom.lengthIsExtensionFromHome
    if isfield(geom, 'Lhome')
        Lhome = geom.Lhome;
    else
        Lhome = home_leg_lengths(geom);
    end
    Lout = Ltotal - Lhome;
else
    Lout = Ltotal;
end
end

%% ========================================================================
function Lhome = home_leg_lengths(geom)
qhome = [0 0 geom.Z0 0 0 0];

B = platform_points(geom.Rb, geom.baseAngles_deg);
P = platform_points(geom.Rp, geom.platAngles_deg);

R = eye(3);
pos = [qhome(1); qhome(2); qhome(3)];

Lhome = zeros(1,6);

for i = 1:6
    Pi_global = pos + R * P(:,i);
    vec = Pi_global - B(:,i);
    Lhome(i) = norm(vec);
end
end

%% ========================================================================
function P = platform_points(radius, angles_deg)
P = zeros(3,6);

for i = 1:6
    a = angles_deg(i) * pi/180;
    P(:,i) = [radius*cos(a); radius*sin(a); 0];
end
end

%% ========================================================================
function R = rotx_mat(a)
ca = cos(a);
sa = sin(a);

R = [1  0   0;
     0  ca -sa;
     0  sa  ca];
end

function R = roty_mat(a)
ca = cos(a);
sa = sin(a);

R = [ ca  0  sa;
       0  1   0;
     -sa  0  ca];
end

function R = rotz_mat(a)
ca = cos(a);
sa = sin(a);

R = [ca -sa  0;
     sa  ca  0;
      0   0  1];
end

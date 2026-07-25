%% Plot desired vs actual Stewart trajectory from length data
% Data columns:
% 1      time
% 2:7    desired pose [X Y Z Roll Pitch Yaw]
% 8:13   desired actuator extensions [mm]
% 14:19  actual actuator extensions [mm]

A = out.T1_DP6_IL6_AL6_ER6;

%% ================= SETTINGS =================
startTime = 100;
maxSamples = 1000;   % reduce if FK is slow

% Your Stewart geometry in mm
geom.Rb = 185;       % base radius [mm]
geom.Rp = 150;       % platform radius [mm]
geom.Z0 = 323.5;     % home height [mm]

% Angles from your working IK geometry
geom.baseAngles_deg = [25 49 145 169 265 289];
geom.platAngles_deg = [0 74 120 194 240 314];

% Your logged lengths look like actuator extension, not full leg length.
% Keep this as true.
geom.lengthIsExtensionFromHome = true;

%% ================= EXTRACT DATA =================
t_all = A(:,1);

Pose_des_logged_all = A(:,2:7);   % [X Y Z Roll Pitch Yaw]
Ldes_all = A(:,8:13);
Lact_all = A(:,14:19);

idx = t_all >= startTime;
idx = idx & all(Lact_all ~= 0, 2);
idx = idx & all(isfinite(Pose_des_logged_all),2);
idx = idx & all(isfinite(Ldes_all),2);
idx = idx & all(isfinite(Lact_all),2);

t = t_all(idx);
Pose_des_logged = Pose_des_logged_all(idx,:);
Ldes = Ldes_all(idx,:);
Lact = Lact_all(idx,:);

t = t - t(1);

%% ================= DOWNSAMPLE FOR FK SPEED =================
N0 = length(t);

if N0 > maxSamples
    id = round(linspace(1, N0, maxSamples));
    t = t(id);
    Pose_des_logged = Pose_des_logged(id,:);
    Ldes = Ldes(id,:);
    Lact = Lact(id,:);
end

N = length(t);

%% ================= FK FROM LENGTHS =================
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

%% ================= EXTRACT XYZ =================
X_des = Pose_des_from_L(:,1);
Y_des = Pose_des_from_L(:,2);
Z_des = Pose_des_from_L(:,3);

X_act = Pose_act_from_L(:,1);
Y_act = Pose_act_from_L(:,2);
Z_act = Pose_act_from_L(:,3);

%% ================= 3D TRAJECTORY =================
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

%% ================= POSITION ERROR =================
pos_err = sqrt((X_des - X_act).^2 + ...
               (Y_des - Y_act).^2 + ...
               (Z_des - Z_act).^2);

rmse_xyz = sqrt(mean(pos_err.^2));
mae_xyz  = mean(abs(pos_err));
max_xyz  = max(abs(pos_err));

fprintf('\nTrajectory position error from FK lengths:\n');
fprintf('RMSE = %.4f mm\n', rmse_xyz);
fprintf('MAE  = %.4f mm\n', mae_xyz);
fprintf('MAX  = %.4f mm\n', max_xyz);

figure;
plot(t, pos_err, 'LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Position error [mm]');
title('3D trajectory position error from lengths');

A = out.T1_DP6_IL6_AL6_ER6;
% =========================
% Settings
% =========================
startTime = 120;      % start comparison after 60 s
resetTimeAxis = true; % true: plot starts from 0 after startTime
% =========================
% Extract data
% =========================
t_all    = A(:,1);
Ldes_all = A(:,8:13);     % desired actuator lengths
Lact_all = A(:,14:19);    % actual actuator lengths
% =========================
% Filter data
% =========================
idx = t_all >= startTime;
% Remove invalid startup rows where feedback is still zero
idx = idx & all(Lact_all ~= 0, 2);
% Remove NaN/Inf rows if any
idx = idx & all(isfinite(Ldes_all), 2) & all(isfinite(Lact_all), 2);
t    = t_all(idx);
Ldes = Ldes_all(idx,:);
Lact = Lact_all(idx,:);
if resetTimeAxis
	t = t - t(1);
end
% Recalculate error after filtering
err = Ldes - Lact;
% =========================
% Metrics
% =========================
rmse_each = sqrt(mean(err.^2, 1));
mae_each  = mean(abs(err), 1);
max_error_each = max(abs(err), [], 1);
metricsTable = table( ...
    (1:6).', ...
    rmse_each.', ...
    mae_each.', ...
    max_error_each.', ...
    'VariableNames', {'Actuator','RMSE_mm','MAE_mm','MaxError_mm'} ...
);
disp(metricsTable)
% =========================
% Plot all actuators
% =========================
figure;
tiledlayout(3,2);
for i = 1:6
    nexttile;
    plot(t, Ldes(:,i), '--', 'LineWidth', 1.2); 
    hold on;
    plot(t, Lact(:,i), 'LineWidth', 1.2);
    grid on;
    xlabel('Time (s)');
    ylabel('Length (mm)');
    legend(['L' num2str(i) ' desired'], ['L' num2str(i) ' actual']);
    title(['L' num2str(i) ' tracking']);
end
sgtitle(['Actuator Tracking From t = ' num2str(startTime) ' s']);
% =========================
% Plot errors
% =========================
figure;
for i = 1:6
    plot(t, err(:,i), 'LineWidth', 1.1);
    hold on;
end
grid on;
xlabel('Time (s)');
ylabel('Error (mm)');
legend('L1 error','L2 error','L3 error','L4 error','L5 error','L6 error');
title(['Actuator Tracking Error From t = ' num2str(startTime) ' s']);

A = out.T1_DP6_IL6_AL6_ER6;

t = A(:,1);
Ldes = A(:,8:13);
Lact = A(:,14:19);

startTime = 120;
idx = t >= startTime;
t = t(idx);
Ldes = Ldes(idx,:);
Lact = Lact(idx,:);

Ts = mean(diff(t));
delay_sec = zeros(1,6);

for i = 1:6
    xd = Ldes(:,i) - mean(Ldes(:,i));
    xa = Lact(:,i) - mean(Lact(:,i));

    [c,lags] = xcorr(xa, xd, 'coeff');
    [~,idxMax] = max(c);

    delay_sec(i) = lags(idxMax) * Ts;
end

disp("Delay per actuator [s]:")
disp(delay_sec)
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

% Small soft penalty to avoid impossible jumps
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
    Lhome = home_leg_lengths(geom);
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
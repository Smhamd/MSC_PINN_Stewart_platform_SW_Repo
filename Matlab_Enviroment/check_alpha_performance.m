%% check_alpha_performance.m
% Compare three Actual_pose_data CSV files against the reconstructed
% X-Z infinity desired trajectory:
% X = 40*sin(w*t), Y = 0, Z = Z0 + 20*sin(2*w*t)
%
% IMPORTANT:
% These uploaded files match Tseg ~= 50 s, not 90 s.
% If your desired generator used another period, change Tseg below.

clear; clc; close all;

files = {
    'Actual_pose_data_0.0.csv', 'PINN alpha = 0.0';
    'Actual_pose_data_0.1.csv', 'PINN alpha = 0.1';
    'Actual_pose_data_0.2.csv', 'PINN alpha = 0.2';
};

% If your downloaded files include "(1)" in the name, change them here:
% files = {
%     'Actual_pose_data_0.0(1).csv', 'PINN alpha = 0.0';
%     'Actual_pose_data_0.1(1).csv', 'PINN alpha = 0.1';
%     'Actual_pose_data_0.2(1).csv', 'PINN alpha = 0.2';
% };

Tseg = 50.0;              % seconds, estimated from your actual data
w = 2*pi/Tseg;
Ax = 40.0;                % mm
Az = 20.0;                % mm
Z0 = 323.5;               % mm, change if your desired Z center is different

results = table();

figure; hold on; grid on; axis equal;
tt = linspace(0,Tseg,1000);
plot(Ax*sin(w*tt), Z0 + Az*sin(2*w*tt), 'LineWidth', 2, 'DisplayName', 'Desired');

figure_x = figure; hold on; grid on;
figure_z = figure; hold on; grid on;
figure_e = figure; hold on; grid on;

for i = 1:size(files,1)
    fname = files{i,1};
    label = files{i,2};

    T = readtable(fname);

    t = T.time_s;
    tau = mod(t,Tseg);

    Xd = Ax*sin(w*tau);
    Yd = zeros(size(t));
    Zd = Z0 + Az*sin(2*w*tau);

    Xa = T.X_matlab_mm;
    Ya = T.Y_matlab_mm;
    Za = T.Z_matlab_mm;

    ex = Xa - Xd;
    ey = Ya - Yd;
    ez = Za - Zd;
    e3 = sqrt(ex.^2 + ey.^2 + ez.^2);

    row = table( ...
        string(label), height(T), t(end), 1/median(diff(t)), 100*mean(T.detected), ...
        rms(ex), mean(abs(ex)), max(abs(ex)), mean(ex), ...
        rms(ey), mean(abs(ey)), max(abs(ey)), mean(ey), ...
        rms(ez), mean(abs(ez)), max(abs(ez)), mean(ez), ...
        rms(e3), mean(e3), max(e3), ...
        'VariableNames', {'Run','Samples','Duration_s','FPS','Detected_percent', ...
        'RMSE_X_mm','MAE_X_mm','MaxAbs_X_mm','Bias_X_mm', ...
        'RMSE_Y_mm','MAE_Y_mm','MaxAbs_Y_mm','Bias_Y_mm', ...
        'RMSE_Z_mm','MAE_Z_mm','MaxAbs_Z_mm','Bias_Z_mm', ...
        'RMSE_3D_mm','MAE_3D_mm','Max_3D_mm'} );

    results = [results; row];

    figure(1);
    plot(Xa, Za, 'LineWidth', 1.2, 'DisplayName', label);

    figure(figure_x);
    plot(t, Xa, 'LineWidth', 1.1, 'DisplayName', label);

    figure(figure_z);
    plot(t, Za, 'LineWidth', 1.1, 'DisplayName', label);

    figure(figure_e);
    plot(t, e3, 'LineWidth', 1.1, 'DisplayName', label);
end

figure(1);
xlabel('X (mm)'); ylabel('Z (mm)');
title('X-Z Infinity: Actual vs Desired');
legend('Location','best');

figure(figure_x);
tt_all = linspace(0, max(results.Duration_s), 2000);
plot(tt_all, Ax*sin(w*mod(tt_all,Tseg)), 'k--', 'LineWidth', 2, 'DisplayName', 'Desired X');
xlabel('Time (s)'); ylabel('X (mm)');
title('X Tracking');
legend('Location','best');

figure(figure_z);
plot(tt_all, Z0 + Az*sin(2*w*mod(tt_all,Tseg)), 'k--', 'LineWidth', 2, 'DisplayName', 'Desired Z');
xlabel('Time (s)'); ylabel('Z (mm)');
title('Z Tracking');
legend('Location','best');

figure(figure_e);
xlabel('Time (s)'); ylabel('3D position error (mm)');
title('3D Position Error');
legend('Location','best');

disp(results);
writetable(results, 'trajectory_performance_metrics_T50.csv');

clear; clc;

baseFolder = "C:\Users\Samer FARAJ\Downloads\Scripts\Calibrate_Frames";
% Change this to the real movement you commanded.
% Example: if x+ means +10 mm, use 10.
step_mm = 30;

files = {
    "pose_home\selected_pose_data.csv"
    "pose_x+\selected_pose_data.csv"
    "pose_x-\selected_pose_data.csv"
    "pose_y+\selected_pose_data.csv"
    "pose_y-\selected_pose_data.csv"
    "pose_z+\selected_pose_data.csv"
    "pose_z-\selected_pose_data.csv"
};

% Known MATLAB robot-frame points
Pm = [
     0,        0,        0;
     step_mm,  0,        0;
    -step_mm,  0,        0;
     0,        step_mm,  0;
     0,       -step_mm,  0;
     0,        0,        step_mm;
     0,        0,       -step_mm
];

Pcv = zeros(7,3);

for i = 1:7
    T = readtable(fullfile(baseFolder, files{i}), ...
                  "VariableNamingRule","preserve");

    if ismember("detected", string(T.Properties.VariableNames))
        detected = string(T.detected);
        T = T(detected == "True" | detected == "true" | detected == "1", :);
    end

    xyz = [T.("X_cam_mm"), T.("Y_cam_mm"), T.("Z_cam_mm")];

    xyz = double(xyz);
    xyz = xyz(~any(isnan(xyz),2), :);

    Pcv(i,:) = mean(xyz, 1);

    fprintf("%s average = [%.3f %.3f %.3f] mm, frames = %d\n", ...
        files{i}, Pcv(i,1), Pcv(i,2), Pcv(i,3), size(xyz,1));
end

[R_cam_to_matlab, t_cam_to_matlab] = rigidTransform3D(Pcv, Pm);

save(fullfile(baseFolder, "camera_to_matlab_frame.mat"), ...
    "R_cam_to_matlab", "t_cam_to_matlab", "Pcv", "Pm", "step_mm");

disp("R_cam_to_matlab:");
disp(R_cam_to_matlab);

disp("t_cam_to_matlab:");
disp(t_cam_to_matlab);

% Check mapping error
Pm_est = (R_cam_to_matlab * Pcv.' + t_cam_to_matlab).';
err = Pm_est - Pm;

disp("Mapping result:");
disp(table(Pm(:,1), Pm(:,2), Pm(:,3), ...
           Pm_est(:,1), Pm_est(:,2), Pm_est(:,3), ...
           vecnorm(err,2,2), ...
           'VariableNames', {'X_true','Y_true','Z_true','X_est','Y_est','Z_est','Error_mm'}));

function [R, t] = rigidTransform3D(Pcv, Pm)

    mu_cv = mean(Pcv, 1).';
    mu_m  = mean(Pm, 1).';

    X = Pcv.' - mu_cv;
    Y = Pm.'  - mu_m;

    H = X * Y.';

    [U, ~, V] = svd(H);

    R = V * U.';

    if det(R) < 0
        V(:, end) = -V(:, end);
        R = V * U.';
    end

    t = mu_m - R * mu_cv;
end
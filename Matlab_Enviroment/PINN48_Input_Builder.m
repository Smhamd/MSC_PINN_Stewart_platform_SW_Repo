function u_pinn48 = PINN48_Input_Builder(pose_desired, L_desired, L_actual_feedback, Ts)
% Build 48-input vector for runtime-safe PC PINN.
%
% Inputs:
%   pose_desired      6x1 [X Y Z Roll Pitch Yaw]
%   L_desired         6x1 ideal IK/current desired lengths [mm]
%   L_actual_feedback 6x1 latest measured feedback [mm]
%   Ts                sample time [s]
%
% Output u_pinn48, 48x1:
%   1:6    pose_desired(k)
%   7:12   L_desired(k)
%   13:18  L_actual(k-1)           latest measured feedback
%   19:24  vL_desired(k)
%   25:30  dirL_desired(k)
%   31:36  vL_actual(k-1)
%   37:42  dirL_actual(k-1)
%   43:48  error(k-1)
%
% Direction convention: samer
%   +1 extending, -1 retracting, 0 nearly stationary

persistent L_des_prev L_actual_prev initialized

eps_velocity = 0.5; % mm/s, same idea as Python --eps

pose_desired = double(reshape(pose_desired, [6,1]));
L_desired = double(reshape(L_desired, [6,1]));
L_actual_feedback = double(reshape(L_actual_feedback, [6,1]));
Ts = double(Ts);

if Ts <= 0 || ~isfinite(Ts)
    Ts = 0.05;
end

if isempty(initialized)
    L_des_prev = L_desired;
    L_actual_prev = L_actual_feedback;
    initialized = true;
end

% Desired velocity at current step, known from desired trajectory.
vL_desired = (L_desired - L_des_prev) ./ Ts;

% Actual previous velocity, computed from latest feedback and previous feedback.
vL_actual_prev = (L_actual_feedback - L_actual_prev) ./ Ts;

dirL_desired = zeros(6,1);
dirL_desired(vL_desired > eps_velocity) = 1;
dirL_desired(vL_desired < -eps_velocity) = -1;

dirL_actual_prev = zeros(6,1);
dirL_actual_prev(vL_actual_prev > eps_velocity) = 1;
dirL_actual_prev(vL_actual_prev < -eps_velocity) = -1;

% Previous tracking error, runtime-safe.
% Uses previous desired command and latest feedback.
error_prev = L_des_prev - L_actual_feedback;

u_pinn48 = zeros(48,1);
u_pinn48(1:6) = pose_desired;
u_pinn48(7:12) = L_desired;
u_pinn48(13:18) = L_actual_feedback;
u_pinn48(19:24) = vL_desired;
u_pinn48(25:30) = dirL_desired;
u_pinn48(31:36) = vL_actual_prev;
u_pinn48(37:42) = dirL_actual_prev;
u_pinn48(43:48) = error_prev;

% Update memory after building current input.
L_des_prev = L_desired;
L_actual_prev = L_actual_feedback;
end

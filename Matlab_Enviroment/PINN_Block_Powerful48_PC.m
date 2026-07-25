function [L_cmd_mm, dL_hat_mm, dL_applied_mm] = PINN_Block_Powerful48_PC(u_pinn48)
% PC-only wrapper for powerful 48-input Stewart residual PINN.
%
% Input u_pinn48 order:
%   1:6    pose_desired(k)
%   7:12   L_desired(k)
%   13:18  L_actual(k-1)
%   19:24  vL_desired(k)
%   25:30  dirL_desired(k)
%   31:36  vL_actual(k-1)
%   37:42  dirL_actual(k-1)
%   43:48  error(k-1)

% =========================
% Hardware safety settings
% =========================
alpha = 0.02;              % start very safe
correctionLimit_mm = 0.10; % first hardware test
predictionLimit_mm = 3.0;  % raw NN clamp

u = double(reshape(u_pinn48, [48,1]));
L_desired_mm = u(7:12);

dL_hat_mm = stewart_powerful48_predict_pc(u);
dL_hat_mm = double(reshape(dL_hat_mm, [6,1]));

% Clamp raw model output
dL_hat_mm = min(max(dL_hat_mm, -predictionLimit_mm), predictionLimit_mm);

% Apply alpha and final safety clamp
dL_applied_mm = alpha .* dL_hat_mm;
dL_applied_mm = min(max(dL_applied_mm, -correctionLimit_mm), correctionLimit_mm);

% Final actuator command
L_cmd_mm = L_desired_mm + dL_applied_mm;
L_cmd_mm = reshape(L_cmd_mm, [6,1]);
end

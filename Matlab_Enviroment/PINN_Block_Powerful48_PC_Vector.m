function y = PINN_Block_Powerful48_PC_Vector(u_pinn48)
% Vector-output version for Simulink Interpreted MATLAB Function block.
%
% Output y = 18x1:
%   1:6   L_cmd_mm
%   7:12  dL_hat_mm
%   13:18 dL_applied_mm

[L_cmd_mm, dL_hat_mm, dL_applied_mm] = PINN_Block_Powerful48_PC(u_pinn48);

y = zeros(18,1);
y(1:6) = L_cmd_mm;
y(7:12) = dL_hat_mm;
y(13:18) = dL_applied_mm;
end

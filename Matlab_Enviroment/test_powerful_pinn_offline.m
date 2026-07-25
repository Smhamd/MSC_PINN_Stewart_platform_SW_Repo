function test_powerful_pinn_offline()
% Quick offline test for the powerful PC PINN model.
% Run after training and saving stewart_powerful18_pc_model.mat.

clear_powerful_pinn_cache();

% Example near home input. Replace with a real row from your logged data if needed.
pose_desired = [0; 0; 323.5; 0; 0; 0];
L_desired = [44; 44; 44; 44; 44; 44];
L_actual_prev = [44; 44; 44; 44; 44; 44];

u_pinn = [pose_desired; L_desired; L_actual_prev];

[L_cmd_mm, dL_hat_mm, dL_applied_mm] = PINN_Block_Powerful18_PC(u_pinn);

disp('dL_hat_mm ='); disp(dL_hat_mm.');
disp('dL_applied_mm ='); disp(dL_applied_mm.');
disp('L_cmd_mm ='); disp(L_cmd_mm.');
end

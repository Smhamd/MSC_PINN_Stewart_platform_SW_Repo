function clear_powerful48_pinn_cache()
% Clear cached PC PINN model and runtime feature memory.

clear stewart_powerful48_predict_pc
clear PINN_Block_Powerful48_PC
clear PINN_Block_Powerful48_PC_Vector
clear PINN48_Input_Builder

disp("Cleared powerful48 PINN cache and input-builder memory.")
end

function clear_powerful_pinn_cache()
% Clear persistent loaded model after retraining or replacing .mat file.
clear stewart_powerful18_predict_pc
clear PINN_Block_Powerful18_PC
clear PINN_Block_Powerful18_PC_Vector
disp('Powerful PINN persistent cache cleared.');
end

POWERFUL 48-INPUT PC PINN WORKFLOW
==================================

1) Create processed CSV files with runtime-safe velocity/direction features.

Single file:
    python add_runtime_safe_features48.py --input Traj1.csv --output Traj1_fulldata.csv --eps 0.5

Folder:
    python add_runtime_safe_features48.py --input-folder "C:\path\raw_csv" --output-folder "C:\path\fulldata_csv" --eps 0.5

2) Train model in MATLAB.

Example:
    folder = "C:\path\fulldata_csv";
    files = dir(fullfile(folder, "*.csv"));
    csvFiles = strings(numel(files),1);
    for i = 1:numel(files)
        csvFiles(i) = fullfile(files(i).folder, files(i).name);
    end
    results = train_stewart_powerful48_pc(csvFiles);

This creates:
    stewart_powerful48_pc_model.mat

3) Offline test:
    test_powerful48_pinn_offline("C:\Users\Samer FARAJ\Downloads\Scripts\Thesis\Training_Data\PINN_Block_Disabled\Without_Backlash\Traj1_fulldata.csv")

4) Simulink runtime:

Use MATLAB Function block:
    PINN48_Input_Builder

Inputs:
    pose_desired      6x1
    L_desired         6x1
    L_actual_feedback 6x1
    Ts                scalar, example 0.05

Output:
    u_pinn48          48x1

Then feed u_pinn48 to:
    PINN_Block_Powerful48_PC

If MATLAB Function block complains about predict/load, use:
    PINN_Block_Powerful48_PC_Vector
inside Interpreted MATLAB Function block.

Vector output dimensions:
    18

Selectors:
    1:6   -> L_cmd_mm
    7:12  -> dL_hat_mm
    13:18 -> dL_applied_mm

5) Hardware safety:

Start with:
    alpha = 0.02
    correctionLimit_mm = 0.10
    predictionLimit_mm = 3.0

Then compare:
    pure IK
    PINN alpha 0.02
    PINN alpha 0.05

Do not use high alpha until actuator tracking improves safely.

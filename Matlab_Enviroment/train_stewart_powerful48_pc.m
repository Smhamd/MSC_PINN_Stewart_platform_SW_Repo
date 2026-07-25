function results = train_stewart_powerful48_pc(csvFiles)
% train_stewart_powerful48_pc
%
% Trains a PC-side powerful residual PINN using runtime-safe dynamic inputs.
%
% Input vector order, 48x1:
%   1:6    pose_desired(k)
%   7:12   L_desired(k)
%   13:18  L_actual(k-1)
%   19:24  vL_desired(k)
%   25:30  dirL_desired(k)
%   31:36  vL_actual(k-1)
%   37:42  dirL_actual(k-1)
%   43:48  error(k-1)
%
% Target:
%   dL_target(k) = L_desired(k) - L_actual(k)
%
% Runtime command:
%   L_cmd(k) = L_desired(k) + alpha*dL_hat(k)
%% ---------------- User settings ----------------
if nargin < 1 || isempty(csvFiles)
    error("Pass csvFiles explicitly, for example: results = train_stewart_powerful48_pc([""Traj1_fulldata.csv""; ""Traj2_fulldata.csv""]);");
end

csvFiles = string(csvFiles(:));

rngSeed = 7;

maxEpochs     = 200;
miniBatchSize = 256;
learnRate     = 5e-4;
valPatience   = 60;

% Important: Keep this low first to remove logging spikes.
% Use 5 for stable training. Use 10 only if you trust the data.
maxAbsTargetForTraining_mm = 5;

modelName = "stewart_powerful48_pc_model.mat";
reportName = "stewart_powerful48_training_report.txt";
predCsvName = "stewart_powerful48_test_predictions.csv";

%% ---------------- Load and build features ----------------
rng(rngSeed);

Xall = [];
Yall = [];
trajIdAll = [];
Tall = table();

for f = 1:numel(csvFiles)
    if ~isfile(csvFiles(f))
        error("CSV file not found: %s", csvFiles(f));
    end

    Ti = readtable(csvFiles(f), "VariableNamingRule", "preserve");
    [Xi, Yi, TiReady] = buildFeaturesOneTrajectory48(Ti);

    n = size(Xi,1);
    Xall = [Xall; Xi]; %#ok<AGROW>
    Yall = [Yall; Yi]; %#ok<AGROW>
    trajIdAll = [trajIdAll; repmat(f,n,1)]; %#ok<AGROW>

    TiReady.TrajID = repmat(f, height(TiReady), 1);
    TiReady.SourceFile = repmat(csvFiles(f), height(TiReady), 1);
    Tall = [Tall; TiReady]; %#ok<AGROW>
end

valid = all(isfinite(Xall),2) & all(isfinite(Yall),2);
Xall = Xall(valid,:);
Yall = Yall(valid,:);
trajIdAll = trajIdAll(valid);
Tall = Tall(valid,:);

% Remove rows with impossible zero feedback in previous actual features.
validActualPrev = all(abs(Xall(:,13:18)) > 1e-9, 2);
Xall = Xall(validActualPrev,:);
Yall = Yall(validActualPrev,:);
trajIdAll = trajIdAll(validActualPrev);
Tall = Tall(validActualPrev,:);

if isfinite(maxAbsTargetForTraining_mm)
    keep = all(abs(Yall) <= maxAbsTargetForTraining_mm, 2);
    fprintf("Keeping %d/%d rows after target limit %.3f mm\n", sum(keep), numel(keep), maxAbsTargetForTraining_mm);
    Xall = Xall(keep,:);
    Yall = Yall(keep,:);
    trajIdAll = trajIdAll(keep);
    Tall = Tall(keep,:);
end

fprintf("Total training-ready samples: %d\n", size(Xall,1));

%% ---------------- Train/validation/test split ----------------
N = size(Xall,1);

if numel(csvFiles) >= 3
    nF = numel(csvFiles);
    nTrainF = max(1, floor(0.70*nF));
    nValF   = max(1, floor(0.15*nF));

    trainF = 1:nTrainF;
    valF   = (nTrainF+1):min(nF, nTrainF+nValF);
    testF  = (max(valF)+1):nF;

    if isempty(testF)
        testF = nF;
        valF = max(1,nF-1);
        trainF = 1:max(1,nF-2);
    end

    idxTrain = ismember(trajIdAll, trainF);
    idxVal   = ismember(trajIdAll, valF);
    idxTest  = ismember(trajIdAll, testF);

    fprintf("Trajectory split:\n");
    fprintf("  Train trajectories: %s\n", mat2str(trainF));
    fprintf("  Val trajectories:   %s\n", mat2str(valF));
    fprintf("  Test trajectories:  %s\n", mat2str(testF));
else
    p = randperm(N);
    nTrain = floor(0.70*N);
    nVal   = floor(0.15*N);

    idxTrain = false(N,1);
    idxVal   = false(N,1);
    idxTest  = false(N,1);

    idxTrain(p(1:nTrain)) = true;
    idxVal(p(nTrain+1:nTrain+nVal)) = true;
    idxTest(p(nTrain+nVal+1:end)) = true;

    fprintf("Random row split because fewer than 3 trajectories were provided.\n");
end

XTrain = Xall(idxTrain,:);
YTrain = Yall(idxTrain,:);
XVal   = Xall(idxVal,:);
YVal   = Yall(idxVal,:);
XTest  = Xall(idxTest,:);
YTest  = Yall(idxTest,:);

fprintf("Rows: Train=%d, Val=%d, Test=%d\n", size(XTrain,1), size(XVal,1), size(XTest,1));

%% ---------------- Normalize using training set only ----------------
xMu  = mean(XTrain, 1);
xSig = std(XTrain, 0, 1);
xSig(xSig < 1e-9) = 1;

yMu  = mean(YTrain, 1);
ySig = std(YTrain, 0, 1);
ySig(ySig < 1e-9) = 1;

XTrainN = single((XTrain - xMu) ./ xSig);
YTrainN = single((YTrain - yMu) ./ ySig);
XValN   = single((XVal   - xMu) ./ xSig);
YValN   = single((YVal   - yMu) ./ ySig);
XTestN  = single((XTest  - xMu) ./ xSig);

%% ---------------- Train powerful PC network ----------------
layers = [
    featureInputLayer(48, "Name", "input", "Normalization", "none")

    fullyConnectedLayer(128, "Name", "fc1")
    reluLayer("Name", "relu1")

    fullyConnectedLayer(128, "Name", "fc2")
    reluLayer("Name", "relu2")

    fullyConnectedLayer(64, "Name", "fc3")
    reluLayer("Name", "relu3")

    fullyConnectedLayer(32, "Name", "fc4")
    reluLayer("Name", "relu4")

    fullyConnectedLayer(6, "Name", "fc_out")
    regressionLayer("Name", "regression")
];

options = trainingOptions("adam", ...
    "InitialLearnRate", learnRate, ...
    "MaxEpochs", maxEpochs, ...
    "MiniBatchSize", miniBatchSize, ...
    "Shuffle", "every-epoch", ...
    "ValidationData", {XValN, YValN}, ...
    "ValidationPatience", valPatience, ...
    "OutputNetwork", "best-validation-loss", ...
    "Verbose", true, ...
    "Plots", "training-progress" ...
    );

net = trainNetwork(XTrainN, YTrainN, layers, options);

%% ---------------- Evaluate in physical units ----------------
YPredN = predict(net, XTestN);
YPred  = double(YPredN).*ySig + yMu;

err = YPred - YTest;
rmsePerLeg = sqrt(mean(err.^2,1));
maePerLeg  = mean(abs(err),1);
maxErrorPerLeg = max(abs(err),[],1);
meanRmse   = mean(rmsePerLeg);
meanMae    = mean(maePerLeg);

fprintf("\n========== POWERFUL 48-INPUT PC TEST RESULTS ==========\n");
fprintf("RMSE per leg [mm]:\n"); disp(rmsePerLeg);
fprintf("MAE per leg [mm]:\n"); disp(maePerLeg);
fprintf("Max error per leg [mm]:\n"); disp(maxErrorPerLeg);
fprintf("Mean RMSE: %.6f mm\n", meanRmse);
fprintf("Mean MAE:  %.6f mm\n", meanMae);

%% ---------------- Save model ----------------
inputFeatureNames = getInputFeatureNames48();

save(modelName, "net", "xMu", "xSig", "yMu", "ySig", ...
    "rmsePerLeg", "maePerLeg", "maxErrorPerLeg", "csvFiles", ...
    "maxAbsTargetForTraining_mm", "inputFeatureNames");

PredTable = table();
for i = 1:6
    PredTable.(sprintf("target_L%d",i)) = YTest(:,i);
    PredTable.(sprintf("pred_L%d",i))   = YPred(:,i);
    PredTable.(sprintf("err_L%d",i))    = err(:,i);
end
writetable(PredTable, predCsvName);

fid = fopen(reportName, "w");
fprintf(fid, "Powerful 48-input PC residual PINN\n\n");
fprintf(fid, "Input order:\n");
for i = 1:numel(inputFeatureNames)
    fprintf(fid, "  %2d: %s\n", i, inputFeatureNames(i));
end
fprintf(fid, "\nTarget: L_desired(k) - L_actual(k)\n");
fprintf(fid, "Mean RMSE [mm]: %.6f\n", meanRmse);
fprintf(fid, "Mean MAE  [mm]: %.6f\n", meanMae);
fprintf(fid, "RMSE per leg [mm]: %s\n", mat2str(rmsePerLeg,6));
fprintf(fid, "MAE per leg [mm]:  %s\n", mat2str(maePerLeg,6));
fprintf(fid, "Max error per leg [mm]: %s\n", mat2str(maxErrorPerLeg,6));
fprintf(fid, "Model: %s\n", modelName);
fclose(fid);

%% ---------------- Plots ----------------
figure("Name","Powerful48 PC PINN target vs prediction");
for i = 1:6
    subplot(3,2,i);
    plot(YTest(:,i), "k"); hold on;
    plot(YPred(:,i), "r");
    grid on;
    title(sprintf("Leg %d", i));
    xlabel("test sample");
    ylabel("correction [mm]");
    legend("target","prediction");
end

figure("Name","Powerful48 PC PINN RMSE per leg");
bar(rmsePerLeg);
grid on;
xlabel("Leg");
ylabel("RMSE [mm]");
title("Powerful 48-input PC PINN correction-target fit RMSE");

%% ---------------- Results struct ----------------
results = struct();
results.net = net;
results.xMu = xMu;
results.xSig = xSig;
results.yMu = yMu;
results.ySig = ySig;
results.rmsePerLeg = rmsePerLeg;
results.maePerLeg = maePerLeg;
results.maxErrorPerLeg = maxErrorPerLeg;
results.meanRmse = meanRmse;
results.meanMae = meanMae;
results.modelName = modelName;
results.inputFeatureNames = inputFeatureNames;
results.targetSource = "computed L_desired(k) - L_actual(k)";
end

%% ========================================================================
function [X, Y, T] = buildFeaturesOneTrajectory48(T)
vars = string(T.Properties.VariableNames);

poseCols = [
    findVar(vars, ["X_desired","X_des","X","x_desired","x_des","X_des_mm"])
    findVar(vars, ["Y_desired","Y_des","Y","y_desired","y_des","Y_des_mm"])
    findVar(vars, ["Z_desired","Z_des","Z","z_desired","z_des","Z_des_mm"])
    findVar(vars, ["Roll_desired","Roll_des","Roll","roll_desired","roll_des","roll"])
    findVar(vars, ["Pitch_desired","Pitch_des","Pitch","pitch_desired","pitch_des","pitch"])
    findVar(vars, ["Yaw_desired","Yaw_des","Yaw","yaw_desired","yaw_des","yaw"])
];

Pose = zeros(height(T),6);
for j = 1:6
    Pose(:,j) = double(T.(poseCols(j)));
end

Ldes = zeros(height(T),6);
Lact = zeros(height(T),6);

vLdes = zeros(height(T),6);
dirLdes = zeros(height(T),6);
LactPrev = zeros(height(T),6);
vLactPrev = zeros(height(T),6);
dirLactPrev = zeros(height(T),6);
errPrev = zeros(height(T),6);

for i = 1:6
    desName = findVar(vars, [
        "L"+i+"_desired", "L"+i+"_des", "L"+i+"_ideal", "L"+i+"_ik", ...
        "L"+i+"_IK", "L"+i+"_desired_mm", "IL"+i, "d"+i
    ]);

    actName = findVar(vars, [
        "L"+i+"_actual", "L"+i+"_act", "L"+i+"_pot_mm", "L"+i+"_pot", ...
        "L"+i+"_measured", "L"+i+"_feedback", "AL"+i
    ]);

    Ldes(:,i) = double(T.(desName));
    Lact(:,i) = double(T.(actName));

    vLdesName = findVar(vars, ["vL"+i+"_desired_mm_s", "vL"+i+"_desired", "L"+i+"_desired_velocity"]);
    dirLdesName = findVar(vars, ["dirL"+i+"_desired", "dirL"+i+"_des"]);

    LactPrevName = findVar(vars, ["L"+i+"_actual_prev", "L"+i+"_actual_k_1", "L"+i+"_actual(k-1)"]);
    vLactPrevName = findVar(vars, ["vL"+i+"_actual_prev_mm_s", "vL"+i+"_actual_prev"]);
    dirLactPrevName = findVar(vars, ["dirL"+i+"_actual_prev"]);
    errPrevName = findVar(vars, ["errorL"+i+"_prev_mm", "L"+i+"_error_prev", "errL"+i+"_prev"]);

    vLdes(:,i) = double(T.(vLdesName));
    dirLdes(:,i) = double(T.(dirLdesName));

    LactPrev(:,i) = double(T.(LactPrevName));
    vLactPrev(:,i) = double(T.(vLactPrevName));
    dirLactPrev(:,i) = double(T.(dirLactPrevName));
    errPrev(:,i) = double(T.(errPrevName));
end

X = [Pose, Ldes, LactPrev, vLdes, dirLdes, vLactPrev, dirLactPrev, errPrev];

Y = Ldes - Lact;

T = T;
for i = 1:6
    T.(sprintf("L%d_target_correction",i)) = Y(:,i);
end
end

%% ========================================================================
function names = getInputFeatureNames48()
names = strings(48,1);
pose = ["X_desired","Y_desired","Z_desired","Roll_desired","Pitch_desired","Yaw_desired"];
for i = 1:6
    names(i) = pose(i);
end
for i = 1:6
    names(6+i) = "L"+i+"_desired";
end
for i = 1:6
    names(12+i) = "L"+i+"_actual_prev";
end
for i = 1:6
    names(18+i) = "vL"+i+"_desired_mm_s";
end
for i = 1:6
    names(24+i) = "dirL"+i+"_desired";
end
for i = 1:6
    names(30+i) = "vL"+i+"_actual_prev_mm_s";
end
for i = 1:6
    names(36+i) = "dirL"+i+"_actual_prev";
end
for i = 1:6
    names(42+i) = "errorL"+i+"_prev_mm";
end
end

%% ========================================================================
function name = findVar(vars, candidates)
candidates = string(candidates);

for c = candidates(:)'
    idx = find(strcmp(vars, c), 1);
    if ~isempty(idx)
        name = vars(idx);
        return;
    end
end

varsLower = lower(vars);
for c = candidates(:)'
    idx = find(strcmp(varsLower, lower(c)), 1);
    if ~isempty(idx)
        name = vars(idx);
        return;
    end
end

error("Could not find any of these columns: %s\nAvailable columns are:\n%s", ...
    strjoin(candidates, ", "), strjoin(vars, ", "));
end

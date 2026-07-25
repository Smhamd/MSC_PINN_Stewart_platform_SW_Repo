function test_powerful48_pinn_offline(csvFile)
% Offline test for powerful 48-input PC PINN using one processed fulldata CSV.
%
% Usage:
%   test_powerful48_pinn_offline("Traj1_fulldata.csv")

if nargin < 1 || isempty(csvFile)
    csvFile = "C:\Users\Samer FARAJ\Downloads\Scripts\Thesis\Training_Data\PINN_Block_Disabled\Without_Backlash\Traj1_fulldata.csv";
end

T = readtable(csvFile, "VariableNamingRule", "preserve");

[X, Y, t] = localBuildX48(T);

YPred = zeros(size(Y));

clear_powerful48_pinn_cache

for k = 1:size(X,1)
    YPred(k,:) = stewart_powerful48_predict_pc(X(k,:).').';
end

err = YPred - Y;

rmse_each = sqrt(mean(err.^2,1));
mae_each = mean(abs(err),1);
max_error_each = max(abs(err),[],1);

metricsTable = table((1:6).', rmse_each.', mae_each.', max_error_each.', ...
    'VariableNames', {'Actuator','RMSE_mm','MAE_mm','MaxError_mm'});
disp(metricsTable)

figure("Name","Powerful48 offline target vs prediction");
for i = 1:6
    subplot(3,2,i);
    plot(t, Y(:,i), "k"); hold on;
    plot(t, YPred(:,i), "r");
    grid on;
    xlabel("time [s]");
    ylabel("correction [mm]");
    legend("target","prediction");
    title("Leg " + i);
end
end

function [X, Y, t] = localBuildX48(T)
vars = string(T.Properties.VariableNames);

t = T.(findVar(vars, ["time"]));

pose = zeros(height(T),6);
poseNames = ["X_desired","Y_desired","Z_desired","Roll_desired","Pitch_desired","Yaw_desired"];
for j = 1:6
    pose(:,j) = double(T.(findVar(vars, poseNames(j))));
end

Ldes = zeros(height(T),6);
Lact = zeros(height(T),6);
LactPrev = zeros(height(T),6);
vLdes = zeros(height(T),6);
dirLdes = zeros(height(T),6);
vLactPrev = zeros(height(T),6);
dirLactPrev = zeros(height(T),6);
errPrev = zeros(height(T),6);

for i = 1:6
    Ldes(:,i) = double(T.(findVar(vars, "L"+i+"_desired")));
    Lact(:,i) = double(T.(findVar(vars, "L"+i+"_actual")));
    LactPrev(:,i) = double(T.(findVar(vars, "L"+i+"_actual_prev")));
    vLdes(:,i) = double(T.(findVar(vars, "vL"+i+"_desired_mm_s")));
    dirLdes(:,i) = double(T.(findVar(vars, "dirL"+i+"_desired")));
    vLactPrev(:,i) = double(T.(findVar(vars, "vL"+i+"_actual_prev_mm_s")));
    dirLactPrev(:,i) = double(T.(findVar(vars, "dirL"+i+"_actual_prev")));
    errPrev(:,i) = double(T.(findVar(vars, "errorL"+i+"_prev_mm")));
end

X = [pose, Ldes, LactPrev, vLdes, dirLdes, vLactPrev, dirLactPrev, errPrev];
Y = Ldes - Lact;
end

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
error("Could not find column: %s", strjoin(candidates,", "));
end

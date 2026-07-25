function dL_hat_mm = stewart_powerful48_predict_pc(u_pinn48)
% PC-only powerful 48-input PINN predictor.
%
% Input order, 48x1:
%   1:6    pose_desired(k)
%   7:12   L_desired(k)
%   13:18  L_actual(k-1)
%   19:24  vL_desired(k)
%   25:30  dirL_desired(k)
%   31:36  vL_actual(k-1)
%   37:42  dirL_actual(k-1)
%   43:48  error(k-1)

persistent net xMu xSig yMu ySig loaded

if isempty(loaded)
    S = load('stewart_powerful48_pc_model.mat', ...
        'net', 'xMu', 'xSig', 'yMu', 'ySig');

    net  = S.net;
    xMu  = double(S.xMu(:).');
    xSig = double(S.xSig(:).');
    yMu  = double(S.yMu(:).');
    ySig = double(S.ySig(:).');

    loaded = true;
end

u = double(reshape(u_pinn48, [1,48]));
x = (u - xMu) ./ xSig;

yN = predict(net, x);

dL_hat_mm = double(yN) .* ySig + yMu;
dL_hat_mm = reshape(dL_hat_mm, [6,1]);
end

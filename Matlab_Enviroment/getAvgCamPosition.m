function p_avg = getAvgCamPosition(csvFile, startTime, endTime)

T = readtable(csvFile);

detected = string(T.detected);
valid = detected == "True";

valid = valid & isfinite(T.X_cam_mm) & isfinite(T.Y_cam_mm) & isfinite(T.Z_cam_mm);

if isfinite(endTime)
    valid = valid & T.time_s >= startTime & T.time_s <= endTime;
else
    valid = valid & T.time_s >= startTime;
end

p_avg = [
    mean(T.X_cam_mm(valid));
    mean(T.Y_cam_mm(valid));
    mean(T.Z_cam_mm(valid))
];

fprintf("\n%s\n", csvFile);
fprintf("Used frames: %d\n", sum(valid));
fprintf("Average = [%.3f; %.3f; %.3f] mm\n", ...
    p_avg(1), p_avg(2), p_avg(3));

end
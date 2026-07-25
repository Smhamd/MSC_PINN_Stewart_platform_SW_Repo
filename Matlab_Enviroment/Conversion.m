% Load the .mat file
data = load('IO6.mat');

% If the file contains one variable, extract it
fieldNames = fieldnames(data);
yourData = data.(fieldNames{1});

% Convert to CSV
writematrix(yourData, 'IO6.csv');   % for numeric data


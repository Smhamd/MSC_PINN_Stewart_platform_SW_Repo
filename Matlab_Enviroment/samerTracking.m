clear variables;
close all;
clc;

% Read the video
videoFile = 'Samer7.mp4'; 
videoReader = VideoReader(videoFile);

% Define the region of interest (ROI)
roiX = 0; % X-coordinate of the top-left corner of the ROI
roiY = 0;  % Y-coordinate of the top-left corner of the ROI
roiWidth = 1700; % Width of the ROI
roiHeight = 2300; % Height of the ROI

% Create a video player to display the video
videoPlayer = vision.VideoPlayer;

% matrix to store the path points
pathPoints = [];


frames = {};
frameIndex = 1;

%loop over frames
while hasFrame(videoReader)
    frames{frameIndex} = readFrame(videoReader);
    frameIndex = frameIndex + 1;
end

% Create a video writer object with 'Motion JPEG AVI' format
outputVideoFile = 'outputVideo.avi';
videoWriter = VideoWriter(outputVideoFile, 'Motion JPEG AVI');
open(videoWriter);

% Process each frame
for k = 1:length(frames)
    % Read the current frame
    frame = frames{k};
    
    % Crop the frame to the region of interest
    roiFrame = imcrop(frame, [roiX roiY roiWidth roiHeight]);
    
    % Convert the ROI frame to HSV color space
    hsvFrame = rgb2hsv(roiFrame);
    
    % Define precise thresholds for red color in HSV space
    hueThresholdLow1 = 0; % Lower bound for hue
    hueThresholdHigh1 = 0.03; % Upper bound for hue
    hueThresholdLow2 = 0.93; % Lower bound for hue
    hueThresholdHigh2 = 1; % Upper bound for hue
    saturationThresholdLow = 0.4; % Lower bound for saturation
    saturationThresholdHigh = .95; % Upper bound for saturation
    valueThresholdLow = 0.5; % Lower bound for value
    valueThresholdHigh = 1; % Upper bound for value
    
    % Create a binary mask for red color based on thresholds
    redMask1 = (hsvFrame(:,:,1) >= hueThresholdLow1 & hsvFrame(:,:,1) <= hueThresholdHigh1);
    redMask2 = (hsvFrame(:,:,1) >= hueThresholdLow2 & hsvFrame(:,:,1) <= hueThresholdHigh2);
    saturationMask = (hsvFrame(:,:,2) >= saturationThresholdLow & hsvFrame(:,:,2) <= saturationThresholdHigh);
    valueMask = (hsvFrame(:,:,3) >= valueThresholdLow & hsvFrame(:,:,3) <= valueThresholdHigh);
    
    % Combine the masks
    redMask = (redMask1 | redMask2) & saturationMask & valueMask;
    
    % Apply the mask to the ROI frame
    redDetectedFrame = roiFrame;
    redDetectedFrame(repmat(~redMask, [1 1 3])) = 0;
    
    % Find the centroid of the detected red region
    stats = regionprops(redMask, 'Centroid');
    
    % If a red region is detected, store its centroid
    if ~isempty(stats)
        centroid = stats(1).Centroid;
        pathPoints = [pathPoints; centroid]; % Store only the centroid within the ROI
    end
    
    % Draw the path on the original frame
    for i = 1:size(pathPoints, 1)
        if pathPoints(i,1) >= 0 && pathPoints(i,1) <= roiWidth && pathPoints(i,2) >= 0 && pathPoints(i,2) <= roiHeight
            frame = insertShape(frame, 'FilledCircle', [pathPoints(i,1) + roiX, pathPoints(i,2) + roiY, 2], 'Color', 'red', 'Opacity', 0.7);
        end
    end
    
    % Write the frame to the output video
    writeVideo(videoWriter, frame);
    
    % Display the original frame with the path
    step(videoPlayer, frame);
end

% Release the video writer and player
close(videoWriter);
release(videoPlayer);

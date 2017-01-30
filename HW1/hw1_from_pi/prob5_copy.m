% Author: Nicholas LaJoie
% ECE 331 - Homework 1, Problem 5
% Date: 1/26/17

%% Plot RPi Memory Speeds

% Read data 
f = '/Users/NicholasRossLaJoie/Desktop/hw1_data.csv';
data = dlmread(f,',',0,0);
bufsize = data(:,1);
start = data(:,2);
stop = data(:,3);

% Plot speed (kb/s) vs. buffer size (int) 
figure(1)
subplot
semilogx(bufsize, ((bufsize*4)/8000)/((stop-start)/1e9), 'LineStyle', 'None','Marker', '*')
title('Memory Speed vs. Data Size')
xlabel('Buffer Size, Int'); % 4 Bytes per Int
ylabel('Speed, kb/s'); 
grid on;
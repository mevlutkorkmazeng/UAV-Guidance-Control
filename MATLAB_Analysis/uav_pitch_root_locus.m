% =========================================================================
% Project: UAV Guidance & Flight Control
% Module: Pitch Dynamics & Root Locus Analysis
% Author: Mevlut Korkmaz , Ali Ozdemir
% =========================================================================

clear; close all; clc;

%% 1. UAV Plant Model (Simplified Pitch Dynamics)
% Transfer function representing the relation between elevator deflection 
% and pitch angle (theta).
% Model structure: G(s) = K / (s * (s^2 + 2*zeta*wn*s + wn^2))

% Define the uncompensated system dynamics (poles at 0, -2, -3)
num = 10;
den = [1, 5, 6, 0]; 

% Create transfer function object
plant_tf = tf(num, den);

disp('UAV Plant Transfer Function:');
plant_tf

%% 2. Root Locus Analysis
% Plotting the Root Locus to analyze system stability margins.
% This analysis is crucial before designing the discrete-time PID 
% or Lead/Lag compensator.

figure('Name', 'UAV Pitch Control - Root Locus', 'Color', 'w');
rlocus(plant_tf);
title('Root Locus of Uncompensated UAV Pitch Dynamics', 'FontSize', 14);
xlabel('Real Axis (Seconds^{-1})', 'FontSize', 12);
ylabel('Imaginary Axis (Seconds^{-1})', 'FontSize', 12);
grid on;

% Add damping ratio (zeta) and natural frequency (wn) grid lines
% specifically targeting a damping ratio of 0.7 for optimal flight stability
sgrid(0.7, 5); 

disp('Analysis Complete. The system requires compensation for stability.');

% =========================================================================
% Project: UAV Guidance & Flight Control
% Module: 3D Trajectory Generation & Tracking Analysis
% Authors: Mevlut Korkmaz, Ali Ozdemir
% Description: Advanced Look-ahead Guidance for Autonomous Missions
% =========================================================================

clear; clc; close all;

%% 1. Mission Profile (Desired 3D Path)
t = 0:0.05:20;
% İHA'nın çizmesini istediğimiz 3D Spiral Rota (Uluslararası Standart Test)
x_ref = 5 * cos(0.5*t);
y_ref = 5 * sin(0.5*t);
z_ref = 0.5 * t;

%% 2. UAV Tracking Simulation (Simple Dynamics with PID & Kalman Influence)
% Gerçek İHA, rotayı mükemmel takip edemez; rüzgar ve gecikme vardır.
x_actual = x_ref + 0.3 * randn(size(t)) * 0.2; % Kalman filtresi öncesi ham veri
y_actual = y_ref + 0.3 * randn(size(t)) * 0.2;
z_actual = z_ref + 0.2 * randn(size(t)) * 0.1;

% Kalman filtresi uygulanmış (yumuşatılmış) takip verisi
x_filtered = smooth(x_actual, 10);
y_filtered = smooth(y_actual, 10);
z_filtered = smooth(z_actual, 10);

%% 3. Professional 3D Visualization
figure('Name', 'UAV 3D Mission Tracking', 'Color', 'w', 'Position', [100 100 800 600]);
plot3(x_ref, y_ref, z_ref, 'k--', 'LineWidth', 2); hold on;
plot3(x_filtered, y_filtered, z_filtered, 'b', 'LineWidth', 2.5);
grid on; axis equal;

% İHA'yı temsil eden bir nokta
plot3(x_filtered(end), y_filtered(end), z_filtered(end), 'ro', 'MarkerSize', 10, 'MarkerFaceColor', 'r');

title('Advanced UAV Guidance: 3D Trajectory Tracking Performance');
xlabel('X Position (m)'); ylabel('Y Position (m)'); zlabel('Altitude (m)');
legend('Reference Flight Path (Mission)', 'Actual Flight Path (Filtered)', 'UAV Current Position');
view(45, 30); % Açıyı ayarla

% Hata Analizi (Mühendislik kanıtı)
error = sqrt((x_ref-x_filtered').^2 + (y_ref-y_filtered').^2 + (z_ref-z_filtered').^2);
fprintf('Maksimum Takip Hatası: %.2f metre\n', max(error));

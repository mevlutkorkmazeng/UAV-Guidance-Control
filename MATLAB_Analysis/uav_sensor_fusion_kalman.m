% =========================================================================
% Project: UAV Guidance & Flight Control
% Module: Sensor Fusion (Kalman Filter Simulation)
% Authors: Mevlut Korkmaz, Ali Ozdemir
% =========================================================================

clear; clc; close all;

% Parametreler
duration = 5;      % saniye
dt = 0.01;         % 100Hz
t = 0:dt:duration;

% Gerçek İHA Açısı (İstediğimiz sabit 10 derece)
true_angle = 10 * ones(size(t));

% Gürültülü Sensör Verisi (Motor titreşimi eklenmiş hali)
measured_angle = true_angle + 2 * randn(size(t)); 

% Kalman Filtresi Hazırlığı
estimate = 0;      % Başlangıç tahmini
P = 1;             % Hata kovaryansı
Q = 0.01;          % Process Noise (Sistem gürültüsü)
R = 0.1;           % Measurement Noise (Sensör gürültüsü)

kalman_output = zeros(size(t));

% Filtreleme Döngüsü
for i = 1:length(t)
    % Tahmin (Predict)
    P = P + Q;
    
    % Güncelleme (Update)
    K = P / (P + R);
    estimate = estimate + K * (measured_angle(i) - estimate);
    P = (1 - K) * P;
    
    kalman_output(i) = estimate;
end

% Görselleştirme
figure('Color', 'w');
plot(t, measured_angle, 'r', 'LineWidth', 0.5); hold on;
plot(t, true_angle, 'k--', 'LineWidth', 2);
plot(t, kalman_output, 'b', 'LineWidth', 2);
legend('Gürültülü Sensör', 'Gerçek Değer', 'Kalman Filtresi Çıktısı');
title('Kalman Filter Performance - Sensor Noise Reduction');
xlabel('Zaman (s)'); ylabel('Açı (Derece)'); grid on;

#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

typedef struct {
    float q; // process noise covariance
    float r; // measurement noise covariance
    float x; // estimated value
    float p; // estimation error covariance
    float k; // kalman gain
} Kalman_t;

void Kalman_Init(Kalman_t *filter, float q, float r, float initial_value);
float Kalman_Update(Kalman_t *filter, float measurement);

#endif

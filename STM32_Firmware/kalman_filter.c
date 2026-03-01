#include "kalman_filter.h"

void Kalman_Init(Kalman_t *filter, float q, float r, float initial_value) {
    filter->q = q;
    filter->r = r;
    filter->x = initial_value;
    filter->p = 1.0f;
}

float Kalman_Update(Kalman_t *filter, float measurement) {
    // Prediction step
    filter->p = filter->p + filter->q;

    // Measurement update step
    filter->k = filter->p / (filter->p + filter->r);
    filter->x = filter->x + filter->k * (measurement - filter->x);
    filter->p = (1.0f - filter->k) * filter->p;

    return filter->x;
}

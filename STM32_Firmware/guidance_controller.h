// =========================================================================
// Project: UAV Guidance & Flight Control
// Module: Discrete-Time Pitch Controller (Header File)
// Authors: Mevlut Korkmaz, Ali Ozdemir
// Affiliation: Ege University, Electrical & Electronics Engineering
// =========================================================================

#ifndef GUIDANCE_CONTROLLER_H
#define GUIDANCE_CONTROLLER_H

#include <stdint.h>

/* * PID_State_t Structure
 * Stores the internal states of the controller to ensure 
 * persistent data between control loop iterations.
 */
typedef struct {
    float integral_error;     // Accumulated error for the I-term
    float prev_error;         // Previous error for the D-term calculation
    float max_output_limit;   // Physical saturation limit for the actuator
} PID_State_t;

/**
 * @brief Initializes the PID controller states and limits.
 * Should be called once during system startup.
 */
void Guidance_Controller_Init(void);

/**
 * @brief Computes the next control command based on current error.
 * @param setpoint_angle Target pitch angle (Degrees)
 * @param measured_angle Current pitch angle from IMU (Degrees)
 * @return Control signal (e.g., PWM duty cycle or Servo angle)
 */
float Guidance_Controller_Update(float setpoint_angle, float measured_angle);

#endif // GUIDANCE_CONTROLLER_H

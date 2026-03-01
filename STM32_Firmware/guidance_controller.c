// =========================================================================
// Project: UAV Guidance & Flight Control
// Module: Discrete-Time Pitch Controller (Bare-metal C)
// Authors: Mevlut Korkmaz, Ali Ozdemir
// =========================================================================

#include <stdint.h>

// Theoretical coefficients derived from MATLAB Root Locus analysis
#define KP 2.5f
#define KI 0.1f
#define KD 0.5f
#define DT 0.01f // 100Hz Control Loop Time

// Structure to hold controller states
typedef struct {
    float integral_error;
    float prev_error;
    float max_output_limit;
} PID_State_t;

PID_State_t pitch_controller;

// Function to initialize the guidance controller
void Guidance_Controller_Init(void) {
    pitch_controller.integral_error = 0.0f;
    pitch_controller.prev_error = 0.0f;
    pitch_controller.max_output_limit = 20.0f; // Maximum physical angle limit for UAV elevator
}

// Main control algorithm, expected to be called at 100Hz (e.g., via Timer Interrupt)
float Guidance_Controller_Update(float setpoint_angle, float measured_angle) {
    float error = setpoint_angle - measured_angle;

    // Proportional Term
    float p_term = KP * error;

    // Integral Term (Note: Advanced anti-windup logic can be added here)
    pitch_controller.integral_error += error * DT;
    float i_term = KI * pitch_controller.integral_error;

    // Derivative Term
    float d_term = KD * ((error - pitch_controller.prev_error) / DT);
    pitch_controller.prev_error = error;

    // Total control signal (Torque/Angle command to the actuators)
    float output = p_term + i_term + d_term;

    // Hardware limitations (Saturation / Actuator Limits)
    if (output > pitch_controller.max_output_limit) {
        output = pitch_controller.max_output_limit;
    } else if (output < -pitch_controller.max_output_limit) {
        output = -pitch_controller.max_output_limit;
    }

    return output;
}

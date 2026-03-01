# UAV Guidance & Flight Control Algorithm

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![MATLAB](https://img.shields.io/badge/MATLAB-e07328?style=for-the-badge&logo=mathworks&logoColor=white)
![STM32](https://img.shields.io/badge/STM32-03234B?style=for-the-badge&logo=stmicroelectronics&logoColor=white)

## Project Overview
This repository contains a discrete-time flight control and guidance algorithm designed for Unmanned Aerial Vehicles (UAVs). The project bridges the gap between theoretical control systems and bare-metal embedded software, a critical requirement for modern defense and aerospace applications.

It features:
* **Mathematical Modeling:** Plant modeling and Root Locus stability analysis using MATLAB.
* **Discrete Control:** Lead/Lag compensator and PID tuning converted into discrete-time equations.
* **Embedded C Implementation:** Optimized, bare-metal C code architecture designed for STM32 microcontrollers.

###  Control System Analysis
Below are the stability and response results obtained from the MATLAB simulations:

| Root Locus Analysis | Step Response Performance |
| :---: | :---: |
| ![Root Locus](UAV%20Stability%20Analysis%20-%20Root%20Locus.png) | ![Step Response](UAV%20Step%20Response.png) |

## Repository Structure
* `/MATLAB_Analysis`: Contains `.m` scripts for transfer functions, Root Locus plots, and step response simulations.
* `/STM32_Firmware`: Contains the core `guidance_controller.c` and `guidance_controller.h` algorithms.

## Engineering Workflow
1. **Analyze:** System stability and margin requirements are verified in MATLAB (s-domain).
2. **Discretize:** Continuous-time controllers are converted to discrete-time (z-domain) for digital execution.
3. **Implement:** The algorithm is written in standard C for real-time execution, ensuring no blocking delays and high performance.

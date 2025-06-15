# Inverted Pendulum Simulator

A C++ simulation of an inverted pendulum system, balanced using fuzzy logic control.

## Overview
This project simulates the dynamics of a cart-pendulum system and applies a Zero-Order Sugeno Fuzzy Inference System to maintain balance. Developed as part of an academic assignment focused on control systems and fuzzy logic.

## Technologies Used
- Language: C++
- Graphics: Simple SDL-based or console output (depending on implementation)
- Control Logic: Custom fuzzy inference engine
- Physics: Second-order differential motion model

## Key Concepts
- Fuzzy logic control
- Trapezoidal membership functions
- Rule-based inference systems
- Real-time feedback loop and dynamic simulation

## Features
- Simulates pendulum behavior and stabilization
- Uses fuzzy rule sets for decision-making
- Optional surface generation for rule calibration


## How to Run
Compile using g++ or your preferred compiler:

```bash
g++ -o pendulum_sim main.cpp pendulum.cpp fuzzy.cpp graphics.cpp -lm
./pendulum_sim

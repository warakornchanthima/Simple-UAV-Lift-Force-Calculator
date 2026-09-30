# Simple-UAV-Lift-Force-Calculator
# UAV Lift Force Calculator

A C program for calculating the aerodynamic lift force
and minimum air velocity required for a UAV to generate
sufficient lift.

## Physics

The lift equation used in this project is:

L = 1/2 * ρ * V² * S * CL

Where:

- L  = Lift force (N)
- ρ  = Air density (kg/m³)
- V  = Air velocity (m/s)
- S  = Wing area (m²)
- CL = Lift coefficient

The UAV weight is calculated by:

W = mg

The minimum velocity required for lift is:

V = √(2mg / (ρSCL))

## Features

- Calculate aerodynamic lift force
- Calculate UAV weight
- Calculate minimum velocity required for lift
- Compare lift force with UAV weight
- Written in C
- Uses basic aerodynamic and physics equations

## Application

This project is intended as a basic aerodynamic calculation
and simulation tool for UAV development and educational purposes.

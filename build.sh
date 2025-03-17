#!/bin/bash

# Build script for Elevator Simulation

# Create build directory if it doesn't exist
mkdir -p build
cd build

# Run qmake to generate Makefile
qmake ../ElevatorSimulation.pro

# Build the project
make -j4

# Check if build was successful
if [ $? -eq 0 ]; then
    echo "Build successful! Run the application with ./ElevatorSimulation"
else
    echo "Build failed!"
fi 
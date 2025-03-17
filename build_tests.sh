#!/bin/bash

# Build script for Elevator Simulation Tests

# Create build directory if it doesn't exist
mkdir -p build_tests
cd build_tests

# Run qmake to generate Makefile
qmake ../tests/tests.pro

# Build the tests
make -j4

# Check if build was successful
if [ $? -eq 0 ]; then
    echo "Test build successful! Run the tests with ./tests"
else
    echo "Test build failed!"
fi 
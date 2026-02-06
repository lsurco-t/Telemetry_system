#!/bin/bash

set -e # Exit on first error

mkdir -p build_tests
cd build_tests

# Build tests
g++ -std=c++17 -I../../include \
    ../test_engine.cpp \
    ../../src/TelemetryEngine.cpp \
    ../../src/TemperatureSensor.cpp \
    ../../src/AltitudeSensor.cpp \
    ../../src/VelocitySensor.cpp \
    -pthread -o test1

g++ -std=c++17 -I../../include \
    ../test_sensors.cpp \
    ../../src/TemperatureSensor.cpp \
    ../../src/AltitudeSensor.cpp \
    ../../src/VelocitySensor.cpp \
    -pthread -o test2

# Run tests
./test1
./test2

echo "All tests passed!"



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
    -pthread -o test_engine

g++ -std=c++17 -I../../include \
    ../test_sensors.cpp \
    ../../src/TemperatureSensor.cpp \
    ../../src/AltitudeSensor.cpp \
    ../../src/VelocitySensor.cpp \
    -pthread -o test_sensors

# Run tests
./test_engine
./test_sensors


echo "All tests passed!"



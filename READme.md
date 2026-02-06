# Satellite Telemetry System (C++)

## 🚀 Project Overview

This project simulates a satellite telemetry system using C++.  
It generates telemetry packets from simulated sensors, processes data in real-time, logs to files, and allows user interaction via a command-line interface (CLI).  

It is designed to demonstrate:

- C++17 proficiency
- Object-oriented design
- Multithreading and synchronization
- File I/O
- STL usage
- System architecture
- Build systems and project structure
- Documentation and testing

This project mirrors real-world flight software systems, making it a perfect portfolio piece for a junior C++ / flight software role.

---

## 🗺️ Roadmap

### Phase 1 — Setup & Skeleton (Day 1)
- Create project structure:
satellite-telemetry/
├── src/
├── include/
├── tests/
├── build/
├── CMakeLists.txt
└── README.md

- Setup CMake and verify build
- Initialize Git repository

Minimal `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(SatelliteTelemetry)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(telemetry
    src/main.cpp
)

Phase 2 — Telemetry Data Model (Day 2)

Create TelemetryPacket struct:

struct TelemetryPacket {
    double temperature;
    double altitude;
    double velocity;
    long timestamp;

    static TelemetryPacket generate();
};


Add constructor and print function

Implement random data generator

Phase 3 — Sensor Simulation (Day 3)

Create Sensor base class:

class Sensor {
public:
    virtual double read() = 0;
};


Derived sensors:

TemperatureSensor

AltitudeSensor

VelocitySensor

Demonstrates inheritance, polymorphism, and abstraction.

Phase 4 — Telemetry Engine + Threading (Day 4)

Create TelemetryEngine class:

Collects sensor data

Generates packets

Runs in a background thread

Stores recent packets

std::vector<TelemetryPacket> buffer;
std::mutex mtx;
std::atomic<bool> running;


Core loop:

while (running) {
    auto packet = TelemetryPacket::generate();
    {
        std::lock_guard<std::mutex> lock(mtx);
        buffer.push_back(packet);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

Phase 5 — Logger System (Day 5)

Create Logger class to write telemetry to telemetry.log:

class Logger {
public:
    void log(const TelemetryPacket& packet);
};


Bonus: CSV export, log rotation

Phase 6 — CLI Interface (Day 6)

Main program loop commands:

start → Start telemetry engine

stop → Stop telemetry engine

latest → Print latest packet

stats → Compute averages, min, max

exit → Quit program

Demonstrates algorithms, STL usage, and interactive CLI design.

Phase 7 — Polish & Testing (Day 7)

Add error handling and input validation

Add unit tests (optional: GoogleTest)

Clean README documentation

Optional: simple performance benchmark

🏗️ Project Architecture
Folder Structure
src/
  main.cpp
  TelemetryEngine.cpp
  Sensor.cpp
  Logger.cpp

include/
  TelemetryPacket.hpp
  TelemetryEngine.hpp
  Sensor.hpp
  Logger.hpp

tests/
build/
CMakeLists.txt
README.md

System Diagram
Sensors
   ↓
TelemetryEngine (threaded)
   ↓
Packet Storage
   ↓
Logger + CLI

🔹 Key Features

Simulated sensors (Temperature, Altitude, Velocity)

Telemetry packet generation

Multithreaded engine

Thread-safe packet storage

CLI interface for control and stats

File logging and optional CSV export

Optional replay and anomaly detection

🔹 Implementation Guide
TelemetryPacket.hpp
#pragma once
#include <chrono>

struct TelemetryPacket {
    double temperature;
    double altitude;
    double velocity;
    long timestamp;

    static TelemetryPacket generate();
};

Random Generation Example
#include <random>
#include <chrono>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> temp(10, 40);

Thread-Safe Storage
std::vector<TelemetryPacket> buffer;
std::mutex mtx;

{
    std::lock_guard<std::mutex> lock(mtx);
    buffer.push_back(packet);
}

Background Thread Example
void TelemetryEngine::run() {
    while (running) {
        auto packet = TelemetryPacket::generate();
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push_back(packet);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

🔹 Advanced Features (Optional)

Circular buffer for memory limits

Anomaly detection (temperature/velocity thresholds)

UDP telemetry streaming

Replay telemetry logs

📝 README Structure

Project Overview → Purpose and context

Features → List key features

Architecture → Diagram and folder structure

Build Instructions

mkdir build
cd build
cmake ..
make


Example Usage → Show CLI commands and output

What I Learned → Highlight skills gained

🎯 Skills Demonstrated

C++17 proficiency

Object-oriented design

Multithreading and synchronization

File I/O and STL usage

System architecture and design patterns

Build systems and project setup (CMake)

Documentation and unit testing

Algorithmic thinking and CLI interaction
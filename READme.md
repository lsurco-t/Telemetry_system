# Satellite Telemetry System (C++)

![CI](https://github.com/lsurco-t/Telemetry_system/workflows/CI/badge.svg)

## 🚀 Project Overview

A telemetry system simulator built with modern C++17. The system collects real-time data from simulated sensors, processes it in a multithreaded engine, and provides an interactive CLI for monitoring and data export.

**Key Highlights:**
- ✅ **Production-ready code** with thread-safety validation
- ✅ **Automated CI/CD** pipeline with GitHub Actions
- ✅ **Thread-safe multithreading** using mutexes and atomics
- ✅ **Real-time sensor simulation** with polymorphic design
- ✅ **Interactive CLI** with comprehensive statistics and CSV export
- ✅ **Comprehensive testing** suite with unit and concurrency tests

---

## 🏗️ Architecture

### System Components

```
┌─────────────────────────────────────────────┐
│         Simulated Sensors                   │
│  ┌──────────┐ ┌──────────┐ ┌─────────────┐  │
│  │Temperature││ Altitude │ │  Velocity   │  │
│  │ 10-40°C   ││100-500km │ │  7-10 km/s  │  │
│  └──────────┘ └──────────┘ └─────────────┘  │
└────────────┬────────────────────────────────┘
             │ (polymorphic read())
             ▼
┌─────────────────────────────────────────────┐
│      TelemetryEngine (Threaded)             │
│  • Collects data every 1 second             │
│  • Thread-safe packet storage               │
│  • Circular buffer (max 1000 packets)       │
│  • std::mutex + std::atomic protection      │
└────────────┬────────────────────────────────┘
             │
             ▼
┌─────────────────────────────────────────────┐
│         CLIController                       │
│  • Interactive command interface            │
│  • Real-time statistics                     │
│  • CSV export with timestamps               │
└─────────────────────────────────────────────┘
```

### Project Structure

```
Telemetry_system/
├── include/                    # Header files
│   ├── Sensor.hpp             # Abstract base class
│   ├── TemperatureSensor.hpp  # Concrete sensor
│   ├── AltitudeSensor.hpp     # Concrete sensor
│   ├── VelocitySensor.hpp     # Concrete sensor
│   ├── TelemetryPacket.hpp    # Data structure
│   ├── TelemetryEngine.hpp    # Multithreaded engine
│   ├── CLIController.hpp      # User interface
│   └── utils.hpp              # String utilities
├── src/                       # Implementation files
│   ├── main.cpp
│   ├── TelemetryEngine.cpp
│   ├── TemperatureSensor.cpp
│   ├── AltitudeSensor.cpp
│   ├── VelocitySensor.cpp
│   ├── CLIController.cpp
│   └── utils.cpp
├── tests/                     # Test suite
│   ├── test_sensors.cpp       # Unit tests for sensors
│   ├── test_engine.cpp        # Unit tests for engine
│   ├── test_concurrency.sh    # Thread safety validation
│   └── tests.sh               # Test runner
├── .github/workflows/         # CI/CD configuration
│   └── ci.yml                 # GitHub Actions workflow
├── CMakeLists.txt             # CMake build configuration
├── Makefile                   # GNU Make build configuration
└── README.md
```

---

## 🎯 Features

✅ **Polymorphic Sensor Simulation** - Three sensor types (Temperature, Altitude, Velocity) with abstract base class  
✅ **Multithreaded Telemetry Engine** - Thread-safe packet collection at 1 Hz with circular buffer (1000 packet limit)  
✅ **Interactive CLI** - 8 commands: start, stop, status, latest, stats, clear, export, exit  
✅ **CSV Data Export** - Auto-generated timestamped filenames with proper formatting  
✅ **Automated Testing** - Unit tests + Valgrind thread safety validation + CI/CD pipeline  
✅ **Dual Build System** - CMake and Makefile support

---

## 🚀 Quick Start

### Prerequisites
- C++17 compatible compiler (g++, clang++)
- Make or CMake
- Valgrind (optional, for thread safety testing)
- Git

### Build with Make
```bash
# Clone the repository
git clone https://github.com/lsurco-t/Telemetry_system.git
cd Telemetry_system

# Build the project
make

# Run the application
./telemetry_system
```

### Build with CMake
```bash
# Create build directory
mkdir build && cd build

# Generate build files and compile
cmake ..
cmake --build .

# Run the application
./telemetry
```

### Running Tests
```bash
# Run all unit tests
cd tests
./tests.sh

# Run thread safety validation (requires Valgrind)
./test_concurrency.sh
```

---

## 💻 Usage Examples

### Basic Workflow
```
$ ./telemetry_system
Telemetry CLI — commands:
  start          Start telemetry collection
  stop           Stop telemetry collection
  status         Show whether the engine is running and buffer size
  latest         Print the latest telemetry packet
  stats          Show basic statistics (avg/min/max) for sensors
  clear          Clear the stored packet buffer
  export <file>  Export packets to CSV file (optional filename)
  exit           Stop telemetry (if running) and exit CLI
  help           Show this help text

Telemetry> start
Telemetry system started.

Telemetry> status
Running: yes
Buffer size: 5

Telemetry> latest
Time : 1770718717
Temp : 22.77
Alt : 209.10
Vel : 9.98

Telemetry> stats
Avg Temp: 25.34
Max Alt: 487.92
Min Vel: 7.12
Packets: 15

Telemetry> export
Data successfully exported to: telemetry_20260210_121530.csv

Telemetry> stop
Telemetry system stopped.

Telemetry> exit
Closing program ...
```

### CSV Export Format
```csv
Temperature, Altitude, Velocity, Timestamp
22.77,209.10,9.98,1770718717
28.43,312.56,8.45,1770718718
19.88,445.21,7.23,1770718719
```

---

## 🧪 Testing & Quality Assurance

### Test Suite
- **Unit Tests**: Validates sensor ranges and engine timing
- **Thread Safety Tests**: Valgrind helgrind validation
- **CI/CD Pipeline**: Automated testing on every push/PR

### Running Specific Tests
```bash
# Sensor range validation
cd tests/build_tests
./test_sensors

# Engine functionality
./test_engine

# Thread safety (with Valgrind)
cd ..
./test_concurrency.sh
```

---

## 🔮 Future Enhancements

### Potential Improvements
- [ ] Add GoogleTest framework for more comprehensive testing
- [ ] Implement anomaly detection (threshold alerts)
- [ ] Add UDP/TCP network streaming
- [ ] Create telemetry replay functionality
- [ ] Add configuration file support (JSON/YAML)
- [ ] Implement data compression for exports
- [ ] Add real-time visualization dashboard
- [ ] Performance profiling and optimization
- [ ] Docker containerization

---

## 👤 Author

**lsurco-t**
- GitHub: [@lsurco-t](https://github.com/lsurco-t)

---

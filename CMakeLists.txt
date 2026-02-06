cmake_minimum_required(VERSION 3.10)
project(SatelliteTelemetry)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCE "src/*.cpp")

add_executable(telemetry ${SOURCES})
cmake_minimum_required(VERSION 3.28) # Specify CMake version.
project(HW_2_AERSP424) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR}/include) # header file folder.
add_executable(Problem1 main1.cpp Sensor.cpp)
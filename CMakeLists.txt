# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(SimpleSQL)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Include the header files directory
include_directories(include)

# Add the source files
file(GLOB SOURCES "src/*.c")

# Add the executable target
add_executable(SimpleSQL ${SOURCES})

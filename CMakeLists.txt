# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(SimpleSQL)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Include the header files directory
include_directories(include)

# List source files explicitly (preferred for debugging)
set(SOURCES
    src/db.c
    src/input.c
    src/main.c
    src/pager.c
    src/table.c
    src/node.c
)

# Add the executable target
add_executable(SimpleSQL ${SOURCES})

cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Task3)

set(SOURCES ./src/Node.cpp ./src/Skiplist.cpp ./src/GameManager.cpp main.cpp)

# Add the executable
add_executable(Task3 ${SOURCES})

# Include directories

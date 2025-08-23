#minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

project(StockExchangeSimulator VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake to look for header files in the 'include' directory
include_directories(include)

# Find all your source files in the 'src' directory
file(GLOB SOURCES "src/*.cpp")

# Create the final executable named "simulator" from your source files
add_executable(simulator ${SOURCES})
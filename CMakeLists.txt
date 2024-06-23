cmake_minimum_required(VERSION 3.0.0)
project(mySpice VERSION 0.1.0 LANGUAGES C CXX)
include_directories(
    ./inc/
    ./src/
)
add_executable(mySpice main.cpp)

include(CTest)
enable_testing()


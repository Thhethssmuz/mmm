cmake_minimum_required(VERSION 2.8.7)
add_definitions(-std=c++11 -Wall -Wextra -pedantic-errors)
enable_testing()

include_directories(src)

option(USE_LIBDW "Compile tests with libdw" OFF)
add_subdirectory(test)

cmake_minimum_required(VERSION 3.0)
project(MMM CXX)

add_library(mmm INTERFACE)

include_directories(src)
target_include_directories(mmm INTERFACE src)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  add_definitions(-DMMM_CLANG)
  target_compile_definitions(mmm INTERFACE MMM_CLANG)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  add_definitions(-DMMM_GNUC)
  target_compile_definitions(mmm INTERFACE MMM_GNUC)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MMM_BUILD_UNIT_TESTS "build unit tests" OFF)
if(MMM_BUILD_UNIT_TESTS)
  enable_testing()
  option(USE_LIBDW "Compile tests with libdw" OFF)
  add_subdirectory(test)
endif()

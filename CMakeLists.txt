cmake_minimum_required(VERSION 3.28)

project(tickforge
  VERSION 0.1.0
  DESCRIPTION "Crypto feed handler, limit order book simulator and backtest engine"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(TF_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(TF_CLANG_TIDY "Run clang-tidy on the project's own targets" OFF)
set(TF_SANITIZE "" CACHE STRING "Sanitizers to enable, e.g. address;undefined or thread")
option(TF_BUILD_TESTS "Build the tests" ON)
option(TF_BUILD_BENCHMARKS "Build the benchmarks" ON)

include(cmake/Dependencies.cmake)
include(cmake/ProjectOptions.cmake)

add_subdirectory(libs/core)
add_subdirectory(libs/record)
add_subdirectory(libs/feed)
add_subdirectory(apps/tf_record)

if(TF_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if(TF_BUILD_BENCHMARKS)
  add_subdirectory(bench)
endif()

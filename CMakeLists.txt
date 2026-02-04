cmake_minimum_required(VERSION 3.20)
project(mapreduce VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_TESTS "Enable unit tests" ON)

add_subdirectory(src)

if (ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
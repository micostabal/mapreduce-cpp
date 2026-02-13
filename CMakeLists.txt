cmake_minimum_required(VERSION 3.20)
project(mapreduce VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

enable_testing()

add_subdirectory(common)
add_subdirectory(proto)
add_subdirectory(worker)
add_subdirectory(master)
add_subdirectory(tests)
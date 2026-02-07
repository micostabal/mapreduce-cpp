add_library(mapreduce
  mapreduce/engine.cpp
  mapreduce/worker.cpp
  mapreduce/worker_task.cpp
  mapreduce/utils/string_utils.cpp
)

target_include_directories(mapreduce
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

target_compile_options(mapreduce PRIVATE
  -Wall -Wextra -Wpedantic
)

add_executable(mapreduce_app main.cpp)
target_link_libraries(mapreduce_app PRIVATE mapreduce)


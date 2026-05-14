
add_library(worker_lib
  worker_task.cpp
  worker.cpp
  master_client.cpp
  worker_service.h
  worker_service.cpp
)

target_link_libraries(worker_lib
  PUBLIC
    proto_master
    common
)

target_include_directories(worker_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(worker
  main.cpp
)

target_link_libraries(worker
  PRIVATE
    worker_lib
)

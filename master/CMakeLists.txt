
add_library(master_lib
  master.cpp
)

target_link_libraries(master_lib
  PUBLIC
    common
)

target_include_directories(master_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(master
  main.cpp
)

target_link_libraries(master
  PRIVATE
    master_lib
)


add_library(common
    utils/string_utils.cpp
)

target_include_directories(common
  PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(common PUBLIC cxx_std_20)
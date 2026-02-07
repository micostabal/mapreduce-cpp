include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(mapreduce_tests
  test_mapper.cpp
  test_worker.cpp
  utils/test_string_utils.cpp
)

target_link_libraries(mapreduce_tests
  PRIVATE
    mapreduce
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(mapreduce_tests)


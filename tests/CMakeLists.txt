include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

# ---- Lib tests ----
add_executable(test_common
  common/utils/test_string_utils.cpp
)

target_link_libraries(test_common
  PRIVATE
    common
    gtest
    gtest_main
)

add_test(NAME common_tests COMMAND test_common)

# ----- Worker Tests

add_executable(test_worker
  worker/test_worker.cpp
)

target_link_libraries(test_worker
  PRIVATE
    worker_lib
    gtest
    gtest_main
)

add_test(NAME worker_tests COMMAND test_worker)

# ----- Master Tests

add_executable(test_master
  master/test_mapper.cpp
)

target_link_libraries(test_master
  PRIVATE
    master_lib
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_common)
gtest_discover_tests(test_worker)
gtest_discover_tests(test_master)

add_test(NAME master_tests COMMAND test_master)

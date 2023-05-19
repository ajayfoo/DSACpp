cmake_minimum_required(VERSION 3.18)

include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(gtest)

enable_testing()
add_executable(
        io_tests
        io_tests.cpp
)

add_executable(
        non_io_tests
        insertion_tests.cpp
)

target_link_libraries(
        non_io_tests PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(non_io_tests)
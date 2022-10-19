cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(gtest)

enable_testing()

add_executable(run_io_tests
        io_tests.cpp
        )

add_executable(run_non_io_tests
        indexing_tests.cpp
)
target_link_libraries(run_non_io_tests
        PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_non_io_tests)
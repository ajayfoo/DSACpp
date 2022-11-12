cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(gtest)

enable_testing()

add_executable(io_tests io_tests.cpp pop_tests.cpp other_tests.cpp peek_tests.cpp)
add_executable(
        non_io_tests
        push_tests.cpp
        pop_tests.cpp
        peek_tests.cpp
        other_tests.cpp
)
target_link_libraries(
        non_io_tests PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(non_io_tests)
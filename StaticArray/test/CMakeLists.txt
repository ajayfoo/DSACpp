cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(gtest)

enable_testing()
add_executable(
        tests
        tests.cpp
)
target_link_libraries(
        tests PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
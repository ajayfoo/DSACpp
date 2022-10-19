cmake_minimum_required(VERSION 3.23)
project(Stack)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

set(DO_TESTS TRUE)

add_subdirectory(src)

if(DO_TESTS)
    add_subdirectory(tests)
    target_link_libraries(io_tests PRIVATE stack)
    target_link_libraries(non_io_tests PRIVATE stack)
endif()
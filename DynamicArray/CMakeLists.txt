cmake_minimum_required(VERSION 3.20)

project(DynamicArray CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS ON)

set(DO_TESTS TRUE)

add_subdirectory(src)

if(DO_TESTS)
    add_subdirectory(tests)
    target_link_libraries(io_tests PRIVATE dynamic_array)
    target_link_libraries(non_io_tests PRIVATE dynamic_array)
endif()
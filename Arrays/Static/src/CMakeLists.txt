cmake_minimum_required(VERSION 3.20)

project(StaticArray CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS ON)

add_subdirectory(static_array)
add_executable(exec_program exec_program.cpp)
target_link_libraries(exec_program PRIVATE static_array)
cmake_minimum_required(VERSION 3.20)

add_subdirectory(static_array)
add_executable(exec_program exec_program.cpp)
target_link_libraries(exec_program PRIVATE static_array)
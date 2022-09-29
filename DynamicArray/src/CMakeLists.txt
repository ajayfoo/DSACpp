cmake_minimum_required(VERSION 3.20)

add_subdirectory(dynamic_array)
add_executable(exec_program exec_program.cpp)
target_link_libraries(exec_program PRIVATE dynamic_array)
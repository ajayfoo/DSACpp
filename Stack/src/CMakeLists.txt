cmake_minimum_required(VERSION 3.23)

add_subdirectory(stack)

add_executable(exec_program exec_program.cpp)

target_link_libraries(exec_program PRIVATE stack)
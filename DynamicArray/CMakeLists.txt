cmake_minimum_required(VERSION 3.20)

project(DynamicArray CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS ON)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(tests PRIVATE dynamic_array)
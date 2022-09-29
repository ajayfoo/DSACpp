cmake_minimum_required(VERSION 3.20)

add_library(static_array STATIC include/static_array.h static_array.cpp)
target_include_directories(static_array PUBLIC include)
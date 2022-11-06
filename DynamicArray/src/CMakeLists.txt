cmake_minimum_required(VERSION 3.20)

add_library(dynamic_array STATIC include/dynamic_array.h)
target_include_directories(dynamic_array PUBLIC include)
set_target_properties(dynamic_array PROPERTIES LINKER_LANGUAGE CXX)
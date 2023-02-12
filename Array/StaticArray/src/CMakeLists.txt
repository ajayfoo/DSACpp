cmake_minimum_required(VERSION 3.20)

add_library(static_array STATIC include/static_array.h)
set_target_properties(static_array PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(static_array PUBLIC include)
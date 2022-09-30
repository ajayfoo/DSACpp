cmake_minimum_required(VERSION 3.23)

add_library(stack STATIC include/stack.h)
set_target_properties(stack PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(stack PUBLIC include)
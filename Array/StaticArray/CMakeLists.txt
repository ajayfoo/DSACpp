cmake_minimum_required(VERSION 3.20)

project(StaticArray CXX)

add_subdirectory(src)

if(DO_TESTS)
    add_subdirectory(tests)
    target_link_libraries(io_tests PRIVATE static_array)
    target_link_libraries(non_io_tests PRIVATE static_array)
endif()

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    if(NOT EXISTS ${CMAKE_SOURCE_DIR}/build/compile_commands.json) 
        file(CREATE_LINK ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/build/compile_commands.json SYMBOLIC)
    endif()
endif()

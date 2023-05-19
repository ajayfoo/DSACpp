cmake_minimum_required(VERSION 3.18)

project(SinglyList CXX)

add_subdirectory(src)

if(DO_TESTS)
    enable_testing()
    add_subdirectory(test) 
    target_link_libraries(io_tests PUBLIC singly_list)
    target_link_libraries(non_io_tests PRIVATE singly_list)
endif()

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    if(NOT EXISTS ${CMAKE_SOURCE_DIR}/build/compile_commands.json) 
        file(CREATE_LINK ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/build/compile_commands.json SYMBOLIC)
    endif()
endif()

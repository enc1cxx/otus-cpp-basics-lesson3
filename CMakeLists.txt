cmake_minimum_required(VERSION 3.12)

project(01.guess_the_number
)

add_executable(guess_the_number
    file_read_write.h
    file_read_write.cpp
    main.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(<target_name> PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(<target_name> PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

set_target_properties(guess_the_number
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
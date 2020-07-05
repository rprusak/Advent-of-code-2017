cmake_minimum_required(VERSION 3.15)
project(day08)

set(CMAKE_CXX_STANDARD 17)

include_directories(../common)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(day08
        main.cpp
        day08.h
        day08.cpp
        ../common/common.cpp
        )
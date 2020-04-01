cmake_minimum_required(VERSION 3.15)
project(day4)

include_directories(../common)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(day4
        main.cpp
        ../common/common.cpp
        )
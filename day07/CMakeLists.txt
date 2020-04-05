cmake_minimum_required(VERSION 3.15)
project(day7)

include_directories(../common)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(day7
        main.cpp
        ../common/common.cpp
        )
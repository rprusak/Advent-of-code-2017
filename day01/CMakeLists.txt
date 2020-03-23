cmake_minimum_required(VERSION 3.13)
project(day01)

set(CMAKE_CXX_STANDARD 17)
include_directories(../common/)

add_executable(day01
        main.cpp
        ../common/common.cpp
        )
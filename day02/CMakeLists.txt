cmake_minimum_required(VERSION 3.15)
project(day02)

include_directories(../common/)
set(CMAKE_CXX_STANDARD 17)

add_executable(day02
        main.cpp
        ../common/common.cpp
        )
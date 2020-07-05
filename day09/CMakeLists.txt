cmake_minimum_required(VERSION 3.15)
project(day09)

set(CMAKE_CXX_STANDARD 17)

set(GTEST_INCLUDE_DIRS /usr/src/googletest/googletest/include)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(../common)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(day09 main.cpp ../common/common.cpp day09.cpp day09.h)
add_executable(day09_tests tests.cpp day09.cpp day09.h)

target_link_libraries(day09_tests gtest gtest_main pthread)
cmake_minimum_required(VERSION 3.17)
project(day13)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(../common)
add_executable(day13 main.cpp ../common/common.cpp day13.h day13.cpp)

set(GTEST_INCLUDE_DIRS /usr/src/googletest/googletest/include)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(day13_tests tests.cpp ../common/common.cpp day13.h day13.cpp)
target_link_libraries(day13_tests gtest gtest_main pthread)
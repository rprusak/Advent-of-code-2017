cmake_minimum_required(VERSION 3.17)
project(day11)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(../common)

add_executable(day11 main.cpp ../common/common.cpp day11.cpp)

set(GTEST_INCLUDE_DIRS /usr/src/googletest/googletest/include)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(day11_tests tests.cpp day11.cpp ../common/common.cpp)
target_link_libraries(day11_tests gtest gtest_main pthread)


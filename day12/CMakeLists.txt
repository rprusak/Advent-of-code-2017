cmake_minimum_required(VERSION 3.17)
project(day12)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(../common)

add_executable(day12 main.cpp day12.h day12.cpp ../common/common.cpp)

set(GTEST_INCLUDE_DIRS /usr/src/googletest/googletest/include)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(da12_tests tests.cpp day12.h day12.cpp ../common/common.cpp)
target_link_libraries(da12_tests gtest gtest_main pthread)
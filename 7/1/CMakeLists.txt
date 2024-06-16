cmake_minimum_required(VERSION 3.10)
project(laba1)

set(CMAKE_CXX_STANDARD 11)

add_library(mainN mainN.cpp)

add_executable(assert assert.cpp)
target_link_libraries(assert mainN)
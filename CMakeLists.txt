cmake_minimum_required(VERSION 3.12)

project(landmasses)

set(CMAKE_CXX_STANDARD 17)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(landmasses src/main.cpp)
target_include_directories(landmasses PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

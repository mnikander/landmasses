cmake_minimum_required(VERSION 3.12)

project(landmasses)

set(CMAKE_CXX_STANDARD 17)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link unit_tests with what we want to test and the GTest and pthread library
add_executable(unit_tests test/main.cpp
                          test/test_clustering.cpp
                          test/test_image.cpp
)
target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread)

add_executable(landmasses src/main.cpp)
target_include_directories(landmasses PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(simplified_landmasses src/simplified_implementation.cpp)
target_include_directories(simplified_landmasses PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(explore_planning_problem)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
find_package(Eigen3)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})
include_directories(./)

add_subdirectory(util)

add_subdirectory(data_structure_and_algorithm)
add_subdirectory(mathematic)
add_subdirectory(auto_drive/planning)



cmake_minimum_required(VERSION 3.10)  
project(example)  
  
find_package(pybind11 CONFIG REQUIRED)  
  
add_library(example MODULE demo_test.cc)  
target_link_libraries(example PRIVATE pybind11::module)
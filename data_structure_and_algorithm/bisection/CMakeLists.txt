add_executable(bisection_test bisection_test.cpp)
target_link_libraries(bisection_test  ${GTEST_LIBRARIES}  pthread)

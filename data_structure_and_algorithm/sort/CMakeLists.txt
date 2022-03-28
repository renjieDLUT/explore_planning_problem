add_executable(sort_test sort_test.cpp)
target_link_libraries(sort_test  ${GTEST_LIBRARIES}  pthread)
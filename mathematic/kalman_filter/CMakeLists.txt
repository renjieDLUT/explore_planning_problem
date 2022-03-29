add_library(kalman kalman.cpp)

add_executable(kalman_test kalman_test.cpp)
target_link_libraries(kalman_test  ${GTEST_LIBRARIES} kalman pthread   matplotlib_cpp)

add_executable(sequence_list data_structure_test.cpp)
target_link_libraries(sequence_list  ${GTEST_LIBRARIES}  pthread)

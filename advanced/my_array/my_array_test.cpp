#include <iostream>

#include "array.h"
#include "gtest/gtest.h"
TEST(MYARRAY, Ctor) {
  Array<int> vec;
  EXPECT_EQ(vec[0], 0);
  EXPECT_EQ(vec.size(), 4);
  vec[1] = 2;
  EXPECT_EQ(vec[1], 2);
}

TEST(MYARRAY, IndexOpt) {
  const Array<int> vec;
  int a = int();

  std::cout << vec[3] << std::endl << a << std::endl;
}
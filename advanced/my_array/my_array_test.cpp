#include "array.h"
#include "gtest/gtest.h"
TEST(MYARRAY, Ctor) {
  Array<int> vec;
  EXPECT_EQ(vec[0], 0);
  EXPECT_EQ(vec.size(), 4);
  vec[1] = 2;
  EXPECT_EQ(vec[1], 2);
}
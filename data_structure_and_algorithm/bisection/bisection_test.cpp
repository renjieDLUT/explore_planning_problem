#include "bisection.h"

#include <algorithm>

#include "gtest/gtest.h"

TEST(bisection_test, normal) {
  std::vector<int> data{2, 4, 5, 2, 6, 3, 6, 7, 1, 9, 11, 2343, 23, 1, 24};
  std::sort(data.begin(), data.end());
  for (auto p : data) std::cout << p << " ";
  std::cout << std::endl;
  std::cout << bisection(0, data.size() - 1, data, 0);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
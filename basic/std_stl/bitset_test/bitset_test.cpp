#include <bitset>
#include <iostream>

#include "gtest/gtest.h"

TEST(bitsetTEST, constructor) {
  std::bitset<10> obj(123);
  std::cout << obj << std::endl;
  std::cout << obj.to_string() << std::endl;

  std::bitset<10> obj1("101001");
  std::cout << obj1.to_ulong() << std::endl;
}

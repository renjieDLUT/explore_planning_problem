#include <iostream>
#include <map>

#include "gtest/gtest.h"

struct Foo {
  Foo(int n) : data(n) {}

  int data;
};

bool operator<(const Foo& lhs, const Foo& rhs) { return lhs.data < rhs.data; }

TEST(MAP, normal) {
  std::map<int, int> map1;
  map1.insert({1, 1});
  map1.insert({3, 9});
  map1.insert({2, 4});

  std::cout << "size: " << map1.size() << std::endl;
  for (auto [key, value] : map1) {
    std::cout << key << " " << value << std::endl;
  }

  std::map<Foo, int> map2;  // std::unordered_map<Foo,int> ,error
  map2.insert({Foo(1), 1});
  map2.insert({Foo(2), 1});
  std::cout << "size: " << map2.size() << std::endl;
}
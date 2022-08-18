#include <iostream>
#include <map>
#include <string>

// #include "gtest/gtest.h"

struct Foo {
  Foo(int n) : data(n) {}

  int data;
};

bool operator<(const Foo& lhs, const Foo& rhs) { return lhs.data < rhs.data; }

void func(std::map<int, int> src) {
  for (auto d : src) {
    std::cout << d.first << std::endl;
  }
}

struct Foo1 {
  int data;
  std::string s1;
  // std::string s2;
  // std::string s3;
  // int data2;
};

void func(std::map<int, std::string>&& src) {
  for (auto& [key, value] : src) {
  }
}

void func(std::string& s) { s = "world"; }

void func1(Foo1&& src) {
  auto& [k1, k2] = src;
  k1 = 10;
  k2 = "renjie";
  src.s1 = "hello";
  func(k2);
}

// TEST(MAP, normal) {
int main() {
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
  const auto& [iter, flag] = map2.insert({Foo(2), 1});
  std::cout << "size: " << map2.size() << std::endl;
  std::cout << (*iter).second << std::endl;
  std::cout << std::boolalpha << flag << std::endl;

  auto [iter1, flag1] = map2.insert({Foo(2), 1});
  std::cout << std::boolalpha << flag1 << std::endl;

  {
    std::map<int, int> map1{{1, 1}, {2, 4}}, map2{{3, 9}};
    // auto node = map1.extract(3);
    map1.merge(map2);
    for (auto [key, value] : map2) {
      std::cout << key << " " << value << std::endl;
    }
    std::map<int, int> map3 = map1;
    for (auto [key, value] : map3) {
      std::cout << key << " " << value << std::endl;
    }
    for (auto [key, value] : map1) {
      std::cout << key << " " << value << std::endl;
    }

    std::map<int, int> map4{{1, 1}, {2, 8}, {3, 27}};
    map1 = std::move(map4);
    for (auto [key, value] : map4) {
      std::cout << key << " " << value << std::endl;
    }
  }
  { func({{1, 1}}); }
  {
    Foo1 obj{1, "hxj"};
    func1(std::move(obj));
    std::cout << obj.s1 << std::endl;
    std::cout << obj.data << std::endl;
  }
}
#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

class Foo {
 public:
  void SetNum(int num) { num_ = num; }

 private:
  int num_ = 3;
};
TEST(STRINGSTREAMTEST, NORMAL) {
  std::stringstream ss;
  ss << "80";
  std::string s;
  ss >> s;
  std::cout << s << std::endl;
  ss.clear();
  Foo obj, obj1;
  obj.SetNum(10);
  ss << obj;
  ss >> obj1;
}
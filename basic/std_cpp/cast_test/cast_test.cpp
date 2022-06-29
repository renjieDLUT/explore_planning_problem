#include <iostream>
#include <string>
#include <vector>

class Foo {
 public:
  Foo(std::string s, int data) : s_(s), data_(data) {}

 private:
  std::string s_;
  int data_;
};

int main() {
  std::vector<char> cVec;
  Foo obj("renjieadadfa", 27);
  std::cout << sizeof(obj);
}
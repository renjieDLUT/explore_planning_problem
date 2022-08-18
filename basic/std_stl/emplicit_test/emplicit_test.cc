#include <iostream>

class Foo {
 public:
  explicit Foo(int num, double data) : num_(num), data_(data) {}

 private:
  int num_;
  double data_;
};

int main() { Foo(3.1, 2); }
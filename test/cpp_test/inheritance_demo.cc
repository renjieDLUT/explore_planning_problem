#include <iostream>

class Base {
public:
  Base() {}
  Base(int num) : num_(num) {}

private:
  int num_;
};

class Derive : public Base {
public:
  using Base::Base;
};

int main() {
  Derive obj;
  Derive obj2();
}

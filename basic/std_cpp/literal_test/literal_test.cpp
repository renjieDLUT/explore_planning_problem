#include <iostream>

class Foo {
 public:
  Foo(int data) : data_(data) {}
  int GetData() { return data_; }

 private:
  int data_;
};

Foo operator"" f(unsigned long long data) { return Foo(data); }

int main() {
  Foo obj = 32f;

  std::cout << obj.GetData();
}
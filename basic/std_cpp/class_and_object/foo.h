#include <initializer_list>
#include <iostream>
#include <vector>
class Foo {
 public:
  Foo(std::initializer_list<int> data) : data_(data) {}
  void PrintData() {
    for (auto d : data_) {
      std::cout << d << " ";
    }
    std::cout << std::endl;
  }

 private:
  std::vector<int> data_;
};
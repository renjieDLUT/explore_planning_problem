#include <initializer_list>
#include <iostream>
#include <vector>
class Foo {
 public:
  Foo(std::initializer_list<int> data) : data_(data), num_(nullptr) {}
  void PrintData() {
    for (auto d : data_) {
      std::cout << d << " ";
    }
    std::cout << std::endl;
    std::cout << *num_ << std::endl;
  }

  void SetNumPtr(double* ptr) { num_ = ptr; }

  void set_num(double num) { *const_cast<double*>(num_) = num; }

 private:
  std::vector<int> data_;
  const double* num_;
};
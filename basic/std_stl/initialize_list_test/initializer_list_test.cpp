#include <initializer_list>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class Foo {
 public:
  Foo() = default;
  Foo(const std::initializer_list<double>& lst) {
    ptr_ = lst.begin();
    size_ = lst.size();
  }
  Foo(const Foo& src) : ptr_(src.ptr_), size_(src.size_) {}

  void Print() {
    for (int i = 0; i < size_; i++) {
      std::cout << *(ptr_ + i) << std::endl;
    }
  }

  //  private:
  const double* ptr_;
  int size_;
};

int main() {
  std::string s({45, 2, 3, 45, 44, 2, 23});
  std::string s1 = {45, 2, 3, 45, 44, 2, 23};

  std::cout << s1 << std::endl;
  std::cout << s1.size() << std::endl;
  std::initializer_list<double> lst;
  lst = {1, 2, 3, 4};

  std::set<double> set1({1, 2, 3});
  std::vector<double> vec{1, 2, 3};

  Foo obj1;

  {
    Foo obj2{1, 2, 3};
    obj1 = obj2;
    obj1.Print();
    std::cout << obj1.ptr_ << std::endl;
  }
  Foo obj3{4, 1, 8};
  // std::vector<int> vec1{9, 8, 7};
  Foo obj4{4, 1, 8};

  obj1.Print();
  std::cout << obj1.ptr_ << std::endl;
  std::cout << obj3.ptr_ << std::endl;
  // obj2.Print();
  std::initializer_list<int> lst1{2, 1, 3};
  std::initializer_list<int> lst2{20, 10, 30};

  std::cout << lst1.begin() << std::endl;

  for (int i = 0; i < lst2.size(); i++) {
    std::cout << *(lst1.begin() + i) << std::endl;
  }
  // obj1.Print();
}

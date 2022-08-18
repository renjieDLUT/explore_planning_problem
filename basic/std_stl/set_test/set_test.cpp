#include <functional>
#include <iostream>
#include <set>
#include <unordered_set>
class Foo {
 public:
  Foo() = default;
  Foo(int data) : data_(data) {}
  int data() { return data_; }
  void SetData(int data) { data_ = data; }

  void Print() { std::cout << data_ << " "; }

  bool operator<(const Foo& src) { data_ < src.data_; }

 private:
  int data_;
};

int main() {
  std::set<std::reference_wrapper<Foo>> set1;
  Foo obj1(1), obj2(3);
  set1.insert(std::ref(obj1));
  set1.insert(std::ref(obj2));

  for (auto obj : set1) {
    obj.get().Print();
  }
  {
    std::unordered_set<int> a{1, 2, 3, 4, 2, 5};

    auto iter = a.find(3);
  }
}
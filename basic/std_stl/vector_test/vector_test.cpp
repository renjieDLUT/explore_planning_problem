#include <iostream>
#include <vector>
class Foo {
 public:
  Foo() = default;
  // Foo(const Foo& src) = delete;
};

int main() {
  std::vector<Foo> vec1;
  vec1.push_back(Foo());

  std::vector<int> vec2{1, 2, 3, 4, 5};
  for (auto it = vec2.begin(); it != vec2.end(); it++) {
    std::cout << *it << " ";
  }
}
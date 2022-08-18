#include <functional>
#include <iostream>

int main() {
  int a = 3;
  int b = 4;
  // std::reference_wrapper<int> ref = a;
  auto ref = std::ref(a);
  ref.get() = 10;
  int c = ref;
  std::cout << "a: " << a << std::endl;
  std::cout << "c: " << c << std::endl;
}
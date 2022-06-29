#include <iostream>
#include <vector>
int main() {
  std::vector<int> a(100, 4);
  std::cout << typeid(a).name() << std::endl;
  std::cout << a.size() << std::endl;
}
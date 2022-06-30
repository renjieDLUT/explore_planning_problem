#include <initializer_list>
#include <iostream>
#include <string>
int main() {
  std::string s({45, 2, 3, 45, 44, 2, 23});
  std::cout << s << std::endl;
  std::cout << s.size() << std::endl;
  std::initializer_list<double> lst;
  lst = {1, 2, 3, 4};
}
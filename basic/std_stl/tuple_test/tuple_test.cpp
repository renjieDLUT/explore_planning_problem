#include <iostream>
#include <string>
#include <tuple>
int main() {
  std::string s("hello");
  auto a = std::make_tuple<std::string, int>(s, 10);
  std::cout << s;
}
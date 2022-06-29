#include <iostream>
#include <stdexcept>
#include <string>
template <typename T>
T Divide(T num, T den) {
  if (den == 0) {
    throw std::invalid_argument("divide by zero");
  }
  return num / den;
}

int main() {
  try {
    Divide(3, 0);
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
  const char* c = "renjie";
  std::cout << (void*)c << std::endl;
  const char* c1 = "renjie";
  long d = (long)c1;
  std::cout << std::hex << std::showbase << std::uppercase << d << std::endl;

  std::string s = "renjie";
  std::cout << std::uppercase << s;
}
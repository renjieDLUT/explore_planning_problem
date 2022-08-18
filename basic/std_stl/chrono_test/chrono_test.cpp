#include <chrono>
#include <iostream>

int main() {
  auto PrintDuration = [](auto& duration) {
    std::cout << duration.count() << std::endl;
  };
  // duration
  std::chrono::duration<long, std::ratio<1>> d1(123);
  std::chrono::duration<double> d2;
  d2 = d2.max();
  std::chrono::duration<long, std::ratio<60>> d3(10);  // 10minutes
  std::chrono::duration<long, std::ratio<1>> d4(14);  //  14s
  

  PrintDuration(d1);
  PrintDuration(d2);
}
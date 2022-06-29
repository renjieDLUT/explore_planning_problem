#include <iostream>

int main() {
  double state = 80;
  const double kPenalty = 0.3494;
  const int kYear = 30;
  const double kInterestRate = 0.03;
  std::cout.precision(4);
  for (int i = 1; i <= kYear; i++) {
    std::cout << "第" << i << "年:" << std::endl;
    // for (int j = 1; j <= 12; j++) {
    //   std::cout.width(10);
    //   state -= kPenalty;
    //   std::cout << state;
    // }
    // state *= (1 + kInterestRate);
    state = state * (1 + kInterestRate) - kPenalty * 12;
    std::cout << state << " " << std::endl;
  }
  {
    unsigned int a = -1;
    std::cout << a << std::endl;
    std::cout << sizeof(a) << std::endl;
  }
}
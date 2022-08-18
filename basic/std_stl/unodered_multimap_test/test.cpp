#include <iostream>
#include <unordered_map>
int main() {
  std::unordered_multimap<int, int> map{{1, 1}, {2, 4}, {3, 9}, {1, 4}};

  // std::unordered_multimap::equal_range()
  auto [iter1, iter2] = map.equal_range(1);
  for (; iter1 != iter2; ++iter1) {
    std::cout << (*iter1).first << " " << (*iter1).second << " ";
  }
  {
    auto p1 = std::make_pair(3, 3);
    auto p2 = std::make_pair(3, 4);
    if (p1 == p2) {
      std::cout << "p1==p2" << std::endl;
    }
  }
  {
    char rho[3] = {static_cast<char>(0b11001111), static_cast<char>(0b10000001),
                   0};
    std::cout << rho << std::endl;
  }
}
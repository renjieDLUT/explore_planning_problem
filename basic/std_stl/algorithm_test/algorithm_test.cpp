#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  auto Print = [](const auto& data) {
    for (auto datum : data) {
      std::cout << datum << " ";
    }
    std::cout << std::endl;
  };

  std::vector<int> vec{2, 16, 4, 5, 3};
  std::sort(vec.begin(), vec.end());
  for (auto d : vec) {
    std::cout << d << " ";
  }

  auto p = std::equal_range(vec.begin(), vec.end(), 7);
  std::cout << std::endl << *p.first << " " << *p.second << std::endl;

  // std::upper_bound()
  // std::lower_bound()
  {
    std::vector<int> vec1{1, 2, 3, 4, 5};
    // int n = std::distance(std::upper_bound(vec1.begin(), vec1.end(), 7),
    //                       vec1.begin());
    int n = std::lower_bound(vec1.begin(), vec1.end(), 7) - vec1.begin();
    std::cout << n << std::endl;
  }
  // std::remove
  // vector::erase
  {
    std::vector<int> a{1, 2, 3, 4, 3, 7};
    auto it = std::remove(a.begin(), a.end(), 3);
    Print(a);
    a.erase(it, a.end());
    Print(a);
  }
  // std::shuffle
  { std::vector<int> a{1, 2, 3, 4, 3, 7}; }
}
#include <iostream>
#include <list>
template <typename T>
void Print(const T& datas) {
  for (auto d : datas) {
    std::cout << d << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::list<int> l1{1, 2, 3, 4};
  std::list<int> l2{5, 6, 7, 8};
  l1.assign({10, 11, 12, 13});
  Print(l1);

  l1.splice(l1.end(), l2);
  Print(l1);
  Print(l2);
}
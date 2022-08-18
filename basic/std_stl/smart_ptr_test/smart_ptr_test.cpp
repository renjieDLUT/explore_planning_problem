#include <iostream>
#include <memory>
#include <vector>
int main() {
  auto uni_ptr1 = std::make_unique<int>(10);
  std::cout << *uni_ptr1 << std::endl;

  std::vector<std::unique_ptr<int>> vec1;
  std::vector <
      // vec1.push_back(std::move(uni_ptr1));  ,,error, unique_ptr cannot copy

      vec1.push_back(std::move(uni_ptr1));
  if (!uni_ptr1) {
    std::cout << "uni_ptr1 is empty" << std::endl;
  }
}
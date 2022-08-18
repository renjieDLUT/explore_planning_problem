#include <iostream>
#include <optional>
#include <vector>
void Foo(std::optional<int*> data) {
  if (!data) {
    std::cout << "data is empty" << std::endl;
    return;
  }
  std::cout << *data.value() << std::endl;
}
int main() {
  std::optional<int> valueOpt;
  auto ptr_opt = std::make_optional<int*>(nullptr);
  if (ptr_opt) {
    std::cout << "ptr_opt is not empty" << std::endl;
  }
  Foo(std::optional<int*>(std::nullopt));

  {
    std::vector<int> vec{1, 2, 3};

    std::optional<std::vector<int>> opt(vec);
    for (auto d : vec) {
      std::cout << d << " " << std::endl;
    }
  }
}
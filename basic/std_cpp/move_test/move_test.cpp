#include <iostream>
#include <string>
#include <vector>
struct Foo {
  std::string s;
  std::vector<int> data;
  int vec[2][2];
};

int main() {
  Foo f1{"renjie", {0, 1, 2, 3}, {0, 1, 2, 3}};
  Foo f2;
  f2 = std::move(f1);
  std::cout << f2.s << std::endl;
  std::cout << f1.s << std::endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << f1.vec[i][j] << " " << f2.vec[i][j] << std::endl;
    }
  }
  {
    std::string s1 = "hello";
    std::string s2 = "world";
    auto &&s = s1;
    // s2 = std::move(s1);
    auto &&s3 = static_cast<std::string &&>(s1);
    s2 = std::move(s3);
    std::cout << s1 << std::endl;
    std::swap(s2, s3);
    std::cout << s3 << std::endl;
  }
  {
    int &&ref = 5;
    std::cout << ref << std::endl;
    auto refAdd = &ref;
    std::cout << refAdd << std::endl;
    ref = 6;
    std::cout << *refAdd << std::endl;
  }
}
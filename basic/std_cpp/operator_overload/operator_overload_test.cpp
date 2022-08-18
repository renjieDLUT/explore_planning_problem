#include <iostream>
#include <vector>
struct Foo {
  int data;
};

Foo operator-(const Foo& src) {
  Foo res;
  res.data = -src.data;
  return res;
}

Foo& operator~(Foo& src) {
  src.data = -src.data;
  return src;
}

void Func(std::vector<int> data) {
  for (auto d : data) {
    std::cout << d << " ";
  }
}

int main() {
  Foo obj{8};
  Foo obj2 = -obj;
  std::cout << obj2.data << std::endl;
  ~obj;
  std::cout << obj.data << std::endl;
  {
    std::vector<int> data{1, 2, 3, 4, 5};
    Func(std::move(data));
    std::cout << "----------------" << std::endl;
    for (auto d : data) {
      std::cout << d << " ";
    }
    std::cout << data.size();
  }
}
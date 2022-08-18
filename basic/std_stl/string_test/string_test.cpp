#include <bitset>
#include <iostream>
#include <locale>
#include <string>
int main() {
  std::string s1 = "hello,world!";
  auto c1 = s1.c_str();
  std::cout << c1 << std::endl;
  s1[3] = 'p';
  std::cout << c1 << std::endl;
  std::cout << s1.size() << std::endl;

  s1 += "任杰";
  std::cout << s1 << std::endl;
  std::cout << s1.size() << std::endl;
  c1 = s1.c_str();
  for (int i = 0; i < 6; i++) {
    std::bitset<8> b = *(c1 + 12 + i);
    std::cout << b.to_string() << " ";
  }
  std::cout << std::endl;
  s1 += "黄雪娟";
  std::cout << s1 << std::endl;
  std::cout << s1.size() << std::endl;
  for (int i = 0; i < 9; i++) {
    std::bitset<8> b = *(c1 + 18 + i);
    std::cout << b.to_string() << " ";
  }
  std::cout << std::endl
            << unsigned(*(c1 + 18) * 65536 + *(c1 + 19) * 256 + *(c1 + 20));
  std::bitset<17> b("01001111011000100");
  std::cout << std::endl << b.to_ulong() << std::endl;
  std::bitset<17> b1("01001011011101010");
  std::cout << b1.to_ulong() << std::endl;
  std::bitset<17> b2("00101101000011111");
  std::cout << b2.to_ulong() << std::endl;

  std::cout.imbue(std::locale("zh_CN.utf8"));
  std::cout << 23564 << std::endl;

  std::cout.imbue(std::locale("C"));
  std::cout << 23564 << std::endl;
}

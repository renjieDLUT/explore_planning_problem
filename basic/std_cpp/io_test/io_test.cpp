#include <fstream>
#include <iostream>

void test() {
  std::ofstream outfile("text2.txt");
  if (!outfile) {
    std::cout << "open text2.txt fail" << std::endl;
    return;
  }
  outfile << 12345;
  std::streampos curpos = outfile.tellp();
  if (curpos == 5) {
    std::cout << "current position is 5";
  }
  outfile.seekp(2, std::ios_base::beg);
  outfile << 0;
  outfile.close();

  std::ifstream fin("text2.txt");
  if (!fin) {
    std::cout << "open text2.txt fail" << std::endl;
    return;
  }
  int var;
  fin >> var;
  if (var == 12045) {
    std::cout << "var==12045";
  }
}

int main() {
  std::ofstream outfile("text.txt", std::ios_base::binary);
  if (!outfile) {
    std::cout << "open fail";
    return -1;
  } else {
    outfile << "ok 123" << 123;
    int a = 132;
    char* c = (char*)&a;
    outfile.write(c, 4);
    outfile.put('c');
  }
  outfile.close();

  outfile.open("text1.txt", std::ios_base::ate);
  outfile << "hello";
  outfile.seekp(std::ios_base::beg);
  outfile << "rj,";
  test();
  return 0;
}
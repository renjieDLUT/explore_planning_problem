/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-04-24 12:05:13
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-04-24 12:10:28
 * @FilePath: /explore_planning_problem/test/cpp_test/set_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <set>
#include <string>

class Foo {
public:
  Foo(int d, std::string name) : data_(d), name_(name) {}

  bool operator<(const Foo &rhs) const { return data_ < rhs.data_; }

private:
  int data_;
  std::string name_;
};

int main() {
  std::set<Foo> s;
  s.insert(Foo(1,"rj"));
  s.insert(Foo(1,"hxj"));

  std::cout << s.size() << std::endl;
}
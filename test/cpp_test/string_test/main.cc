/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-17 16:17:41
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-05-21 17:07:19
 * @FilePath: /explore_planning_problem/test/cpp_test/string_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <vector>

struct Foo {

  std::vector<Foo> sub_foo;
};

int main() {
  std::string s("hello");
  for (auto iter = s.begin(); iter != s.end() - 1; ++iter) {
    std::cout << *iter;
  }

  Foo f;
  f.sub_foo.push_back(Foo());
  std::cout << f.sub_foo.size();

  {
    std::string s = "hello \nrenjie\n";
    std::cout << s;
  }
}
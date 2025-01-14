/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-17 19:06:39
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-17 19:32:02
 * @FilePath: /explore_planning_problem/test/cpp_test/binear_search/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>

struct MyType {
  std::unordered_map<int, int> map_data;
  uint64_t index;
};

int main() {
  std::deque<MyType> data;
  MyType a;
  a.index = 1;
  data.push_back(a);
  a.index = 2;
  data.push_back(a);
  a.index = 3;
  data.push_back(a);
  a.index = 4;
  data.push_back(a);
  a.index = 5;
  data.push_back(a);

  int index = 0;
  a.index = 3;
  std::binary_search(data.begin(), data.end(), a, [&index](MyType a, MyType b) {
    if (a.index == b.index)
      index = a.index;
    return a.index < b.index;
  });
  std::cout << index << std::endl;
  std::cout << (*(data.begin() + 3)).index << std::endl;
}
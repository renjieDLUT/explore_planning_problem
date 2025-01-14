/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-17 18:48:12
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-17 18:49:21
 * @FilePath: /explore_planning_problem/test/cpp_test/deque_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <deque>
#include <iostream>
int main() {
  std::deque<int> data{1, 2, 3, 4};
  for (auto d : data) {
    std::cout << d << " ";
    data.pop_front();
  }
}
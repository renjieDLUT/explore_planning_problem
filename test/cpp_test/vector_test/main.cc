/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-04-24 18:20:29
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-04-29 18:49:21
 * @FilePath: /explore_planning_problem/test/cpp_test/vector_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
void foo(std::vector<int> input) { std::cout<<"input:" << input.size() << std::endl; }


template <typename T>
bool InRange(T&& lower, T&& upper, T&& value) {
  if (value < lower || value > upper) {
    return false;
  }
  return true;
}

int main() {
  std::vector<int> data{1, 2, 3};

  foo(std::move(data));
  std::cout<<"data:" << data.size() << std::endl;

  std::cout<<InRange(1,2,3)<<std::endl;
}
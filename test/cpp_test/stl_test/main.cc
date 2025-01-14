/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-06-04 17:31:28
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-06-04 17:32:04
 * @FilePath: /explore_planning_problem/test/cpp_test/stl_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<double> data{1, 2, 3, 4};

  std::for_each(data.begin(), data.end(),
                [](double x) { std::cout << x << " "; });
}
/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-02-20 16:18:29
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-02-21 14:59:01
 * @FilePath: /explore_planning_problem/test/cpp_test/pimpl_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "foo.h"
int GetNum() { return 4; }

int main() {
  Foo f;
  f.fun();
  const auto &data = GetNum();
}
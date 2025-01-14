/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-02-20 16:14:23
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-05-24 19:30:28
 * @FilePath: /explore_planning_problem/test/cpp_test/pimpl_test/foo.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <memory>

class FooImpl;

class Foo {
public:
  Foo();
  ~Foo(){}
  void fun();
  // void Fun(FooImpl f);

private:
  std::unique_ptr<FooImpl> ptr_;
};
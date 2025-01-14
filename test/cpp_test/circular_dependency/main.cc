/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-16 12:20:05
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-16 12:23:25
 * @FilePath:
 * /explore_planning_problem/test/cpp_test/circular_dependency/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 *
 */
#include <iostream>

class B;
class A {
public:
private:
  B* data_;
};

class B {
public:
private:
  A data_;
};

int main(){
    std::cout<<"hello world"<<std::endl;
}
/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-19 15:37:45
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-19 16:12:10
 * @FilePath: /explore_planning_problem/test/cpp_test/namespace_test/foo2.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "foo2.h"

#include <iostream>
void foo2(MyType tmp) { std::cout << tmp.data << std::endl; }

void foo2(){
    MyType data=foo1();
    std::cout<<data.data<<std::endl;
    std::cout<<"\033[31mThis is an error message\033[0m";
}

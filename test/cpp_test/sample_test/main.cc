/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-18 12:13:56
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-18 12:15:16
 * @FilePath: /explore_planning_problem/test/cpp_test/sample_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
 
int main()
{
    std::string in {"ddad"}, out;
    std::sample(in.begin(), in.end(), std::back_inserter(out), 4,
                std::mt19937 {std::random_device{}()});
    std::cout << "Four random letters out of " << in << " : " << out << '\n';
}
/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-18 15:31:52
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-18 15:32:12
 * @FilePath: /explore_planning_problem/test/cpp_test/time_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>  

#include <iomanip>  

#include <ctime>  

  

int main() {  

    std::time_t now = std::time(nullptr);  

    std::tm *local_time = std::localtime(&now);  

    std::cout << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << std::endl;  

    return 0;  

}
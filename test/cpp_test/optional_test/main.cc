/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-17 17:34:42
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-17 17:34:56
 * @FilePath: /explore_planning_problem/test/cpp_test/optional_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <optional>
#include<iostream>

std::optional<std::string> get_scenairo_id() {
  if (std::string().empty()) {
    return std::nullopt;
  }
  return "hello";
}

int main(){
    std::cout<<get_scenairo_id<<std::endl;

    
}
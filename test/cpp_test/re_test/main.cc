/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-04-23 14:16:14
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-04-23 15:59:16
 * @FilePath: /explore_planning_problem/test/cpp_test/re_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <regex>
#include <string>
int main() {
  {

    std::string s = "run/targe/free";
    std::regex match_re("\\w+(/\\w+)*");
    std::regex search_re("\\w+");

    std::smatch m;

    std::cout << "match: " << std::regex_match(s, match_re) << std::endl;
    std::regex_search(s, m, search_re);
    std::cout << "prefix:" << m.prefix() << std::endl;
    for (int i = 0; i < m.size(); ++i) {
      std::cout << m[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "suffix: " << m.suffix() << std::endl;

    auto begin_iter = std::sregex_iterator(s.begin(), s.end(), search_re);
    for (; begin_iter != std::sregex_iterator(); ++begin_iter) {
      std::smatch m = *begin_iter;
      std::cout << "m.size: " << m.size() << " prefix:" << m.prefix()
                << "       m:" << m.str()<<"      suffix:"<<m.suffix() << std::endl;
    }
  }
}
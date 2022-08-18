#include <algorithm>
#include <iostream>
#include <regex>
// regex 表示某个特定正则表达式的对象
// match_results 匹配正则表达式的子字符串，包括所有的捕捉组
// sub_match

int main() {
  std::regex r("\\d{4}/([0-9]|1[0-2])/([1-9]|[1-2][0-9]|3[0-1])");
  std::string s;
  std::cin >> s;
  // regex_match 匹配正则表达式
  if (std::regex_match(s, r)) {
    std::cout << "valid data." << std::endl;
  } else {
    std::cout << "invalid data." << std::endl;
  }

  // regex_search( )  用于查找字符串中的匹配的子字符串
  {
    std::regex r("//\\s*(.+)$");
    std::string s;
    std::cin >> s;
    // std::getline(std::cin, s);
    std::smatch m;
    if (std::regex_search(s, m, r)) {
      std::cout << " Found comment ' " << m[1] << " '" << std::endl;
    } else {
      std::cout << " No comment found!" << std::endl;
    }
  }
  {
    std::regex r("(\\d{4})/([01][0-9])");
    std::string s;
    std::cin >> s;
    const std::sregex_iterator end;
    for (std::sregex_iterator iter(std::cbegin(s), std::cend(s), r);
         iter != end; iter++) {
      std::cout << "\"" << (*iter)[1] << "\"" << std::endl;
    }
  }

  // regex_replace()
}

/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-15 17:47:03
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-06-28 14:28:28
 * @FilePath: /explore_planning_problem/test/cpp_test/tmp.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE<>
 */
#include <chrono>
#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstring>

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type fun(T a, T b) {
  return a + b;
}
using DataFrameType =
    std::vector<std::pair<std::string, std::vector<std::string>>>;

DataFrameType data_;

template <typename T, typename = decltype(std::to_string(std::declval<T>()))>
void AppendOneRecord(std::unordered_map<std::string, T> record) {
  for (auto &[key, value] : data_) {
    T tmp = record[key];
    value.push_back(std::to_string(tmp));
  }
}

struct MyData {
  int first;
  int second;
};

int main() {
  double res = fun<double>(1., 2.);
  std::cout << res << std::endl;

  std::vector<std::pair<std::string, std::string>> data;
  data.push_back({"name", "rj"});
  data.push_back({"age", "29"});
  for (auto [k, v] : data) {
    std::cout << k << " " << v << std::endl;
  }

  {
    data_.push_back({"name", {}});
    data_.push_back({"age", {}});

    std::unordered_map<std::string, double> record;
    record.insert({"name", 18});
    record.insert({"age", 18});

    AppendOneRecord(record);
  }

  {
    const MyData data{1, 1};
    std::cout << std::to_string(data.second);
    std::cout << std::to_string(false) << std::endl;
  }
  {
    std::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{6, 7, 8, 9, 10};
    a.insert(a.begin(), b.begin(), b.end());
    for (auto d : a) {
      std::cout << d << " ";
    }
  }
  {
    std::cout << std::endl;
    std::cout << 8 / 3. / 2. << std::endl;
  }
  {
    std::cout << int(7.0) << std::endl;
    for (int i = 0; i < 1000000; ++i) {
      int a = int(i * 1.0);
      if (i * 1.0 - a > 0.1) {
        std::cout << a << " " << i << std::endl;
      }
    }
  }
  std::array<int, 10000> a{0};
  std::array<int, 10000> b{0};
  {
    auto t1 = std::chrono::system_clock::now();
    for (int i = 0; i < a.size(); ++i) {
      b[i] = a[i];
    }
    auto t2 = std::chrono::system_clock::now();
    std::cout << "cost time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                     .count()<<std::endl;
  }
    {
    auto t1 = std::chrono::system_clock::now();
    std::memcpy(b.data(),a.data(),40000);
    auto t2 = std::chrono::system_clock::now();
    std::cout << "cost time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                     .count();
  }
}
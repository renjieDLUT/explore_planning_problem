/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-17 15:00:17
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-17 15:00:38
 * @FilePath: /explore_planning_problem/test/cpp_test/csv_writer/test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "csv_writer.h"

int main() {
  std::vector<std::string> fields{"name", "age", "city", "height", "weight"};
  std::string save_path = "/tmp";
  CsvWriter csv_handler(fields, save_path);

  std::unordered_map<std::string, std::string> string_fields;
  std::unordered_map<std::string, double> double_fields;
  std::unordered_map<std::string, int> int_fields;

  string_fields["name"] = "limei";
  string_fields["city"] = "beijing";

  double_fields["height"] = 160.0;
  double_fields["weight"] = 60.0;

  int_fields["age"] = 20;

  csv_handler.AppendOneRecord(string_fields, double_fields, int_fields);
}
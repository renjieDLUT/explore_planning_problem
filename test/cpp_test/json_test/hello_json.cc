/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-19 14:36:54
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-19 19:43:23
 * @FilePath: /explore_planning_problem/test/cpp_test/json_test/hello_json.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <fstream>
#include <iostream>
#include <sstream>

#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace nlohmann::literals::json_literals;

namespace {
struct Person {
  std::string name;
  std::string address;
  int age;
  std::vector<int> nums;
};

void to_json(json &j, const Person &p) {
  j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
}

void from_json(const json &j, Person &p) {
  j.at("name").get_to(p.name);
  j.at("address").get_to(p.address);
  j.at("age").get_to(p.age);
}
} // namespace

int main() {

  // 构建json对象
  json j;
  j["pi"] = 3.141;
  j["happy"] = true;
  j["name"] = "Niels", j["nothing"] = nullptr;
  j["answer"]["everything"] = 42;
  j["list"] = {0, 1, 2};
  j["object"] = {{"currency", "usd"}, {"value", 452.99}};

  std::cout << j << std::endl;

  // 获取并打印json元素值
  float pi = j.at("pi");
  bool is_happy = j.at("happy");
  auto tmp = j.at("nothing");

  std::string name = j.at("name");
  int everything = j.at("answer").at("everything");

  std::cout << pi << " " << is_happy << " " << tmp << " " << name << " "
            << everything << std::endl;
  std::cout << typeid(tmp).name() << std::endl;
  std::cout << tmp.is_null() << " " << tmp.size() << std::endl;

  auto list = j.at("list");
  std::cout << list.is_array() << std::endl;
  std::cout << list.size() << std::endl;
  for (int i = 0; i < list.size(); ++i) {
    std::cout << i << " ";
  }
  auto currency = j.at("object").at("currency");
  std::cout << currency << std::endl;

  // 写json对象到.json文件中
  std::ofstream of("pretty.json");
  of << j << std::endl;
  of.close();
  // string 序列化和反序列化
  {
    json j = R"({"happy":true,"pi":3.14})"_json;
    std::cout << j.at("pi") << std::endl;
  }

  // stream的序列化和反序列化
  {
    json j;

    std::cin >> j;
    std::cout << j << std::endl;
    std::cout << "j.is_object: " << j.is_object() << std::endl;
    std::cout << "j.is_array: " << j.is_array() << std::endl;
    std::cout << "j.is_string: " << j.is_string() << std::endl;

    std::ifstream ifile("pretty.json");
    ifile >> j;
    std::cout << j << std::endl;
  }

  // 任意类型转换
  {
    Person p{"renjie", "beijing", 29};
    json j = p;
    std::cout << j << std::endl;
    auto p2 = j.get<Person>();
  }

  //转换json到二进制格式
  // json格式非常常用,但是缺点:并不是一种紧凑的格式,不适合通过网络传输,或则写到本地.
  {
    json j = R"({"name":"renjie"})"_json;
    std::vector<std::uint8_t> v_bson = json::to_bson(j);

    std::ofstream of("tmp.bson");
    for (auto datum : v_bson) {
      of << datum;
    }
    of.close();

    std::ifstream ifile("tmp.bson", std::ios::binary);
    std::vector<std::uint8_t> deserialize_bson;

    while (!ifile.eof() && ifile.peek() != -1) {
      std::cout << ifile.peek() << " ";
      char c = ifile.get();
      deserialize_bson.push_back(c);
    }
    for (auto c : v_bson) {
      std::cout << c;
    }
    std::cout << std::endl;
    for (auto c : deserialize_bson) {
      std::cout << c;
    }
    std::cout << std::endl;

    for (auto c : v_bson) {
      std::cout << int(c) << " ";
    }
    std::cout << std::endl;
    for (auto c : deserialize_bson) {
      std::cout << int(c) << " ";
    }
    std::cout << std::endl;

    json deserialize_json = json::from_bson(deserialize_bson);
    std::cout << "Deserialize:" << deserialize_json << std::endl;
  }
  {
    std::istringstream ss("hello world");
    while (!ss.eof()) {
      char c = ss.get();
      std::cout << c << " ";
    }
  }
  {
    json j{{"name", "rj"}, {"age", 29}};
    json sub_j{{"hxj", 29}, {"cqy", 55}};
    j["friend"] = sub_j;
    std::cout << j << std::endl;
  }
}

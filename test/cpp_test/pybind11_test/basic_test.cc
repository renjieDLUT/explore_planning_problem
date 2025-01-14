/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-05-08 14:55:15
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-05-08 17:27:35
 * @FilePath:
 * /explore_planning_problem/test/cpp_test/pybind11_test/pybind11_test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include <iostream>
#include <string>
#include <vector>

namespace py = pybind11;

int add(int i, int j) { return i + j; }

class Person {
public:
  Person(std::string name) : name_(name) {}

  static void Print() { std::cout << "person class"; }

  std::vector<int> get_data() { return data_; }
  void add_data(int i) { data_.push_back(i); }
  std::string name_;
  std::vector<int> data_;
};

class PersonFactory {
public:
  PersonFactory() = default;

  Person CreatePerson() { return Person("hello"); }

  std::vector<Person> CreatePersons() { return {CreatePerson()}; }
};

PYBIND11_MODULE(basic_raw, m) {
  m.doc() = "pybind11 example plugin";
  m.def("add", &add, "A function that adds two numbers", py::arg("i"),
        py::arg("j"));

    py::class_<Person> pet(m, "Person");
    pet.def(py::init<std::string>());
    pet.def("get_data", &Person::get_data);
    pet.def("add_data", &Person::add_data);
    pet.def_readwrite("name", &Person::name_);
    pet.def_static("print",&Person::Print);

  py::class_<PersonFactory> factory(m, "PersonFactory");
  factory.def(py::init<>());
  factory.def("create_person", &PersonFactory::CreatePerson);
  factory.def("create_persons", &PersonFactory::CreatePersons);
}

/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-02-23 11:49:44
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-02-23 11:49:47
 * @FilePath: /explore_planning_problem/test/python_test/pybing_test/demo_test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <pybind11/pybind11.h>  
  
namespace py = pybind11;  
  
// 一个简单的C++函数  
int add(int i, int j) {  
    return i + j;  
}  
  
PYBIND11_MODULE(example, m) {  
    m.doc() = "pybind11 example plugin"; // 可选：为模块添加文档字符串  
    m.def("add", &add, "A function which adds two numbers");  
}
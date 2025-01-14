/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-14 17:10:52
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-14 18:14:25
 * @FilePath: /explore_planning_problem/test/cpp_test/thread_test/mutex_test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
// 1. 非定时的互斥体类
// std::mutex, 标准的具有独占所有权语义的互斥体类
// std::recursive_mutex,
// std::shared_mutex

// 2. 定时的互斥体类
// std::timed_mutex
// std::recursive_timed_mutex
// std::shared_timed_mutex

// 锁
// std::lock_guard
// std::unique_lock
// std::shared_lock
// std::scoped_Lock

std::mutex mut;
int data = 0;

void fun() {
  std::lock_guard<std::mutex> lock(mut);
  for (int i = 0; i < 10; ++i) {
    ++data;
  }
}

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 1000; i++) {
    threads.emplace_back(fun);
  }
  
  for(auto& thread:threads){
    thread.join();
  }
  std::cout << "data:" << data << std::endl;
}

/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-14 23:18:00
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-15 00:19:06
 * @FilePath:
 * /explore_planning_problem/test/cpp_test/thread_test/condition_variable_test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>

std::mutex mut;
std::queue<std::string> message;

std::condition_variable cv;

void producer() {
  for (int i = 0; i < 100; ++i) {
    {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::unique_lock<std::mutex> lock(mut);
      std::cout << "produce " << i << std::endl;
      message.push("producer " + std::to_string(i));
      cv.notify_all();
    }
  }
}

void consumer() {
  std::unique_lock<std::mutex> lock(mut);
  static int count = 0;
  while (true) {
    cv.wait(lock);
    // while (!message.empty()) {
      message.pop();
      std::cout << "count:" << count++ << std::endl;
    // }
  }
}

int main() {
  std::thread thread_consume(consumer);
  std::thread thread_product(producer);

  thread_consume.join();
  thread_product.join();
}
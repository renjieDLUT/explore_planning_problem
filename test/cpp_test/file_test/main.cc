/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-01-17 10:25:00
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-01-19 12:10:39
 * @FilePath: /explore_planning_problem/test/cpp_test/file_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <boost/filesystem.hpp>
#include <iomanip>
#include <iostream>

int main() {
  char s[] = "tmp/renjie_ws/tmp/tmp";
  boost::filesystem::path dir(s); // 创建一个表示文件夹的路径对象
  std::cout << dir.c_str();
  if (boost::filesystem::create_directories(dir)) { // 创建文件夹
    std::cout << "Folder created successfully!" << std::endl;
  } else {
    std::cout << "Failed to create folder." << std::endl;
  }

  {
    std::string file_path = "tmp/tmp/tmp.txt";
    boost::filesystem::path file(file_path);
    std::cout << file.extension() << std::endl;
    std::cout << (file.extension().string() == ".txt");
    std::cout << (".txt" == ".txt") << std::endl;
  }

  {
    boost::filesystem::path basePath("/home/user/");

    std::string relativePath("documents/file1.txt");

    // 使用/操作符进行路径拼接

    boost::filesystem::path fullPath = basePath / "docu";

    std::cout << "Full path: " << fullPath << std::endl;
  }

  {
    boost::filesystem::path dir(
        "/home/renjie/renjie_ws/practice/explore_planning_problem/"
        "test"); // 替换为你要查询的目录路径

    for (boost::filesystem::directory_iterator iter(dir);
         iter != boost::filesystem::directory_iterator(); ++iter) {

      if (boost::filesystem::is_regular_file(iter->status())) {

        std::cout << iter->path().string() << std::endl;
      }
    }
  }
  {
    boost::filesystem::path dir(
        "/home/renjie/renjie_ws/practice/explore_planning_problem/"
        "test");
    for (boost::filesystem::recursive_directory_iterator iter(dir);
         iter != boost::filesystem::recursive_directory_iterator(); ++iter) {

      if (boost::filesystem::is_regular_file(iter->status())) {

        std::cout << iter->path().filename().string() << std::endl;
      }
    }
  }
  return 0;
}
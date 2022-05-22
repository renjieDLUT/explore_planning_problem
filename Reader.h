#pragma once

#include <string>
class Reader{
  public:
  Reader()=default;
  Reader(std::string topic):topic_(topic){}

  private:
    std::string topic_; 
};
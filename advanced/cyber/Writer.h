#pragma once

#include<string>
#include"message.h"
class Writer{
public:
  Writer()=default;
  Writer(std::string topic):topic_(topic){}
  void Publish(Message &msg);

  private:
  std::string topic_;
};

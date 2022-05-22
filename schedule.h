#pragma once
#include<map>
#include"message.h"
#include"Reader.h"
#include"Writer.h"
// 这个类应该写成 singleton 单例模式
typedef void(*pFun)(Message*);
// class Writer;
class Schedule{
 public:
  Schedule()=delete;

  static void Trigger(std::string topic, Message* msg){
    if(channels_.find(topic)!=channels_.end()){
      auto callback= channels_[topic];
      callback(msg);
    }
  }

  static  Reader CreateReader(std::string topic, pFun callback){
    channels_[topic]= callback;
    return Reader(topic);
  }

  static Writer  CreateWriter(std::string topic){
      return Writer(topic);
  }

  private:

    static std::map<std::string, pFun> channels_;
};

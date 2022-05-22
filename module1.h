#pragma once

#include"module.h"
#include"Reader.h"
#include<functional>
#include"schedule.h"
#include<iostream>
class Module1:public Module{
  public:
   Module1() { wrap_fun_=std::bind(&Module1::callback,this,std::placeholders::_1); }
   virtual void Init() override {
     reader_ = Schedule::CreateReader("/planning", Wrap);
   }

  static void Wrap(Message* msg){
    wrap_fun_(msg);
  }

   void callback(Message* msg){
     std::cout<<"Module1:  i get message, msg.num:"<<msg->num<<" msg.sequence:"<<msg->sequence<<std::endl;
      this->msg=*msg;
   }

   virtual void Proc() override {}

  private:
   Reader reader_;
   Message msg;
   static std::function<void(Message*)> wrap_fun_;

};
std::function<void(Message*)> Module1::wrap_fun_;
#pragma once

#include"module.h"
#include"Writer.h"
#include"schedule.h"
class Module2:public Module{
  public:
    void Init(){
      writer_=Schedule::CreateWriter("/planning");
    }
    void Proc(){
      Message msg;
      msg.num=1;
      msg.sequence=2;
      writer_.Publish(msg);
    }

  private:
    Writer writer_;

};
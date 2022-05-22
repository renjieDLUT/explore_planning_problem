#include"schedule.h"
#include"module1.h"
#include"module2.h"
int main(){
  Module1 m1;
  Module2 m2;
  m1.Init();
  m2.Init();
  m2.Proc();
}
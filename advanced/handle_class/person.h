#pragma once
#include "address.h"
#include "date.h"

class Person {
 public:
  Person(Date date, Address address) : date_(date), address_(address) {}
  Address GetAddress();

 private:
  Date date_;
  Address address_;
};
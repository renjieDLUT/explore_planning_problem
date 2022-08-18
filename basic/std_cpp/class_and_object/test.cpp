#include "foo.h"
#include "gtest/gtest.h"
TEST(PRACTICE, initializer_list_test) {
  Foo obj = {1, 2, 3, 4, 5};
  double num = 10;
  obj.SetNumPtr(&num);
  obj.set_num(99);
  obj.PrintData();
}
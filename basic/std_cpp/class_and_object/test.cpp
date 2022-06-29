#include "foo.h"
#include "gtest/gtest.h"
TEST(PRACTICE, initializer_list_test) {
  Foo obj = {1, 2, 3, 4, 5};
  obj.PrintData();
}
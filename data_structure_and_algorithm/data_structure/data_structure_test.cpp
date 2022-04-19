#include <gtest/gtest.h>

#include "sequence_list.h"
#include "sequence_list2.h"

TEST(sequence_list, initial) {
  int data[] = {1, 2, 3, 4};
  SequenceList<int> list(data, 4);
  list.PrintList();
}

TEST(sequence_list, clear) {
  int data[] = {1, 2, 3, 4};
  SequenceList<int> list(data, 4);
  list.Clear();
  list.PrintList();
}

TEST(sequence_list, empty) {
  int data[] = {1, 2, 3, 4};
  SequenceList<int> list(data, 4);
  EXPECT_EQ(false, list.Empty());
  list.Clear();
  EXPECT_EQ(true, list.Empty());
}

TEST(sequence_list, length) {
  int data[] = {1, 2, 3, 4};
  SequenceList<int> list(data, 4);
  EXPECT_EQ(4, list.Length());
  std::cout << "list.capacity: " << list.Capacity() << std::endl;
}

TEST(sequence_list, retrival) {
  int data[] = {1, 2, 3, 4};
  SequenceList<int> list(data, 4);
  EXPECT_EQ(2, list.Get(1));
}

TEST(sequence_list, locate) {
  int data[] = {1, 2, 3, 4};
  SequenceList<int> list(data, 4);
  EXPECT_EQ(2, list.Locate(3));
  EXPECT_EQ(-1, list.Locate(5));
}

TEST(sequence_list, insert) {
  int data[] = {1, 2, 3, 4};
  SequenceList<int> list(data, 4);
  list.Insert(7, 3);
  list.PrintList();
}

TEST(sequence_list, delete1) {
  int data[] = {1, 2, 3, 4};
  SequenceList<int> list(data, 4);
  list.Delete(3);
  list.PrintList();
}

TEST(sequence_list2, initial) {
  SequenceList2<int> list;
  std::cout << list.GetIncrement() << std::endl;
  int data[201] = {1};
  SequenceList2<int> list2(data, 201);
  std::cout << list2.GetCapacity() << std::endl;
  std::cout << list2.GetLength() << std::endl;
  list2.Print();
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
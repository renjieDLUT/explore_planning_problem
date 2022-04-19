/**
 * @file sequence_list2.h
 * @author renjie (renjie_dlut2016@163.com)
 * @brief 线性表，采用动态分配存储数据
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
template <class T>
class SequenceList2 {
 public:
  SequenceList2();
  SequenceList2(T input[], int n);
  ~SequenceList2();
  int GetIncrement() { return increment_; }
  int GetCapacity() { return capacity_; }
  int GetLength() { return length_; }
  void Print();

 private:
  const int increment_ = 100;
  int length_;
  int capacity_;
  T* dataPtr_;
};

template <class T>
SequenceList2<T>::SequenceList2() {
  capacity_ = increment_;
  dataPtr_ = new T[capacity_];
}

template <class T>
SequenceList2<T>::SequenceList2(T input[], int n) {
  capacity_ = (n / increment_ + 1) * increment_;
  dataPtr_ = new T[capacity_];
  for (int i = 0; i < n; i++) {
    dataPtr_[i] = input[i];
  }
  length_ = n;
}

template <class T>
SequenceList2<T>::~SequenceList2() {
  delete[] dataPtr_;
}

template <class T>
void SequenceList2<T>::Print() {
  for (int i = 0; i < length_; i++) {
    std::cout << dataPtr_[i] << " ";
  }
  std::cout << std::endl;
}
/**
 * @brief
 *  线性表：n个同类型的数据元素，元素之间是一对一的关系，除第0个元素外，均有一个前驱元素；除最后一个元素外，均有一个后继元素
 *  采用静态分配的数组来存储线性表里的数据
 *
 */
#include <iostream>
#define MAXSIZE 100

template <class T>
class SequenceList {
 public:
  SequenceList() { length_ = 0; }
  SequenceList(T input[], int n);
  ~SequenceList() {}
  void Clear() { length_ = 0; }
  bool Empty();
  int Length() { return length_; }
  int Capacity();
  T Get(int index);
  int Locate(T elem);
  void Insert(T elem, int index);
  void Delete(int index);
  void PrintList();

 private:
  T data_[MAXSIZE];
  int length_;
};

template <class T>
SequenceList<T>::SequenceList(T input[], int n) {
  if (n > MAXSIZE) throw " n > maxsize ";
  length_ = n;
  for (int i = 0; i < n; i++) {
    data_[i] = input[i];
  }
}

template <class T>
bool SequenceList<T>::Empty() {
  return length_ == 0 ? true : false;
}

template <class T>
int SequenceList<T>::Capacity() {
  return MAXSIZE;
}

template <class T>
T SequenceList<T>::Get(int index) {
  if (index > length_ - 1) throw "index > length-1";
  if (index < 0) throw "index < 0";
  return data_[index];
}

template <class T>
int SequenceList<T>::Locate(T elem) {
  for (int i = 0; i < length_; i++) {
    if (data_[i] == elem) return i;
  }
  return -1;
}

template <class T>
void SequenceList<T>::Insert(T elem, int index) {
  if (length_ + 1 > MAXSIZE) throw "length + 1 > MAXSIZE";
  if (index > length_) throw "index > length";
  if (index < 0) throw "index<0";
  length_++;
  for (int i = length_ - 1; i >= index; i--) {
    data_[i + 1] = data_[i];
  }
  data_[index] = elem;
}

template <class T>
void SequenceList<T>::Delete(int index) {
  if (index >= length_) throw "index>=length_";
  if (index < 0) throw "index<0";
  for (int i = index; i < length_ - 1; i++) {
    data_[index] = data_[index + 1];
  }
  length_--;
}

template <class T>
void SequenceList<T>::PrintList() {
  for (int i = 0; i < length_; i++) {
    std::cout << data_[i] << " ";
  }
  std::cout << std::endl;
}
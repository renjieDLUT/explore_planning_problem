#pragma once
#include <memory>
#include <utility>
template <typename T>
class Array;

template <typename T>
void Swap(Array<T>& lhs, Array<T>& rhs);

template <typename T>
class Array {
 public:
  friend void Swap<T>(Array<T>& lhs, Array<T>& rhs);

  Array();
  virtual ~Array();
  // delete copy constructor method and copy operator method
  Array(const Array<T>& src) = delete;
  Array<T>& operator=(const Array<T>& src) = delete;

  // move constructor method and move operator method
  Array(Array<T>&& rhs);
  Array<T>& operator=(Array<T>&& rhs);

  void Resize(unsigned int size);

  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;

  unsigned int size() const { return size_; }

 private:
  static const unsigned int kDefaultSize = 4;

  unsigned int size_;
  T* ptr_;
};

template <typename T>
void Swap(Array<T>& lhs, Array<T>& rhs) {
  std::swap(lhs.size_, rhs.size_);
  std::swap(lhs.ptr_, rhs.ptr_);
}

template <typename T>
Array<T>::Array() {
  size_ = kDefaultSize;
  ptr_ = new T[size_]{};
}

template <typename T>
Array<T>::~Array() {
  delete[] ptr_;
  ptr_ = nullptr;
}

template <typename T>
void Array<T>::Resize(unsigned int size) {
  auto new_array = std::make_unique<T[]>(size);
  for (unsigned int i = 0; i < size_; i++) {
    new_array[i] = ptr_[i];
  }

  delete[] ptr_;
  size_ = size;
  ptr_ = new_array.release();
}

template <typename T>
Array<T>::Array(Array<T>&& rhs) {
  delete[] ptr_;
  ptr_ = rhs.ptr_;
  size_ = rhs.size_;

  rhs.ptr_ = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& rhs) {
  if (this == &rhs) {
    return *this;
  }

  Array<T> tmp(std::move(rhs));
  Swap(*this, tmp);
  return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
  if (size_ <= index) {
    Resize(index + kDefaultSize);
  }
  return ptr_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
  if (size_ <= index) {
    throw std::out_of_range("");
  }

  return ptr_[index];
}
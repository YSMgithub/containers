#ifndef S21_CONTAINERS_SRC_HEADERS_S21_VECTOR_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21_VECTOR_HPP_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <class T>
class vector {
 private:
  T* arr_;

  size_t size_;

  size_t capacity_;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
#include "../s21_vector/s21_vectorIterator.inc"

  vector();
  explicit vector(size_type n);
  explicit vector(std::initializer_list<T> const& items);
  vector(const vector& v);
  vector(vector&& v);
  ~vector();
  vector operator=(vector&& v);
  reference at(size_type pos);
  T& operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();
  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector& other);
  template <typename... Args>
  iterator emplace(const_iterator pos, Args&&... args);
  template <typename... Args>
  void emplace_back(Args&&... args);
};
#include "../s21_vector/s21_vectorMehods.inc"

}  // namespace s21

#endif  // S21_CONTAINERS_SRC_HEADERS_S21_VECTOR_HPP_

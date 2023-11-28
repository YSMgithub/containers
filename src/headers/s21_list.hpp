#ifndef S21_CONTAINERS_SRC_HEADERS_S21_LIST_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21_LIST_HPP_

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {

template <typename T>

class list {
 public:
#include "../s21_list/s21_listIterator.inc"
#include "../s21_list/s21_listNode.inc"

  using const_iterator = typename list<T>::listConstIterator;

  list();
  explicit list(size_t n);
  explicit list(std::initializer_list<T> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);
  const T &front();
  const T &back();
  iterator begin();
  iterator end();
  const_iterator cbegin();
  const_iterator cend();
  bool empty();
  size_t size();
  size_t max_size();
  void clear();
  iterator insert(iterator pos, const T &value);
  void erase(iterator pos);
  void push_back(const T &value);
  void pop_back();
  inline void push_front(const T &value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();
  template <class... Args>
  iterator emplace(const_iterator pos, Args &&...args);
  template <class... Args>
  void emplace_back(Args &&...args);
  template <class... Args>
  void emplace_front(Args &&...args);

 private:
  size_t _size;
  list<T>::listNode *head;
  iterator last_elem();
  const_iterator clast_elem();
};

#include "../s21_list/s21_listMethods.inc"

}  // namespace s21

#endif  // S21_CONTAINERS_SRC_HEADERS_S21_MAP_HPP_

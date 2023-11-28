#ifndef S21_CONTAINERS_SRC_HEADERS_S21_QUEUE_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21_QUEUE_HPP_

#include "s21_list.hpp"

namespace s21 {
template <typename T>
class queue {
 private:
  s21::list<T> list;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() : list() {}
  explicit queue(std::initializer_list<value_type> const &items)
      : list(items) {}
  queue(const queue &s) : list(s.list) {}
  queue(queue &&s) : list(std::move(s.list)) {}
  ~queue() {}

  queue &operator=(queue &&s) {
    list.clear();
    list = std::move(s.list);
    return *this;
  }

  const_reference front() { return list.front(); }

  const_reference back() { return list.back(); }

  bool empty() { return list.empty(); }

  size_type size() { return list.size(); }

  void push(const_reference value) { list.push_back(value); }

  void pop() { list.pop_front(); }

  void swap(queue &other) { list.swap(other.list); }

  template <class... Args>
  void emplace_back(Args &&...args) {
    list.emplace_back(args...);
  }
};
}  // namespace s21

#endif  // S21_CONTAINERS_SRC_HEADERS_S21_QUEUE_HPP_

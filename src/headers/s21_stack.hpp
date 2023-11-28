#ifndef S21_CONTAINERS_SRC_HEADERS_S21_STACK_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21_STACK_HPP_

#include "s21_list.hpp"

namespace s21 {
template <typename T>
class stack {
 private:
  s21::list<T> list;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack() : list() {}
  explicit stack(std::initializer_list<value_type> const &items)
      : list(items) {}
  stack(const stack &s) : list(s.list) {}
  stack(stack &&s) : list(std::move(s.list)) {}
  ~stack() {}

  stack &operator=(stack &&s) {
    list.clear();
    list = std::move(s.list);
    return *this;
  }

  const_reference top() { return list.back(); }

  bool empty() { return list.empty(); }

  size_type size() { return list.size(); }

  void push(const_reference value) { list.push_back(value); }

  void pop() { list.pop_back(); }

  void swap(stack &other) { list.swap(other.list); }

  template <class... Args>
  void emplace_front(Args &&...args) {
    list.emplace_front(args...);
  }
};
}  // namespace s21

#endif  // S21_CONTAINERS_SRC_HEADERS_S21_STACK_HPP_

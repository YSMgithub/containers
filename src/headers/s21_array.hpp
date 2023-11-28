#ifndef S21_CONTAINERS_SRC_HEADERS_S21__ARRAY_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21__ARRAY_HPP_
#include <iostream>
namespace s21 {
template <class T, size_t _size>
class array {
 public:
  using iterator = T *;
  using const_iterator = const T *;

  array() = default;
  ~array() = default;

  explicit array(std::initializer_list<T> const &items) {
    int i = 0;
    for (auto &elem : items) {
      _array[i] = elem;
      i++;
    }
  }

  array(const array &a) {
    for (size_t i = 0; i < _size; i++) {
      _array[i] = a._array[i];
    }
  }

  array(array &&a) = default;

  array &operator=(array &&a) = default;

  T &at(size_t pos) {
    if (pos >= _size) {
      throw std::out_of_range("Out of bounds array");
    }
    return _array[pos];
  }

  T &operator[](size_t pos) { return _array[pos]; }

  const T &front() { return _array[0]; }

  const T &back() { return _array[_size - 1]; }

  iterator data() { return _array; }

  ///

  iterator begin() { return _array; }

  iterator end() { return (_array + _size - 1); }

  ///

  bool empty() { return (_size == 0); }

  size_t size() { return _size; }

  size_t max_size() { return _size; }

  ///

  void swap(array &other) {
    if (_size != other.size()) {
      throw std::out_of_range("Different array sizes");
    }
    for (size_t i = 0; i < _size; i++) {
      T tmp;
      tmp = _array[i];
      _array[i] = other._array[i];
      other._array[i] = tmp;
    }
  }

  void fill(const T &value) {
    for (size_t i = 0; i < size(); i++) {
      _array[i] = value;
    }
  }

 private:
  T _array[sizeof(T) * _size] = {};
};
}  // namespace s21

#endif  // S21_CONTAINERS_SRC_HEADERS_S21__ARRAY_HPP_

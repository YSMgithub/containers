#ifndef S21_CONTAINERS_SRC_HEADERS_S21_MULTISET_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21_MULTISET_HPP_

#include <initializer_list>

#include "s21_set.hpp"

namespace s21 {

template <class Key>
class multiset : public set<Key> {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = typename btree<Key, Key>::iterator;
  using const_iterator = typename btree<Key, Key>::iterator;
  using set<Key>::set;

 public:
  explicit multiset(std::initializer_list<key_type> const &keys)
      : set<Key>::set(keys, false) {}
  std::pair<iterator, bool> insert(const key_type &key) override {
    return std::pair<iterator, bool>(this->tree.insert(key, key), true);
  }
};

}  //  namespace s21

#endif  // S21_CONTAINERS_SRC_HEADERS_S21_MULTISET_HPP_

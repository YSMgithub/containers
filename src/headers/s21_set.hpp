#ifndef S21_CONTAINERS_SRC_HEADERS_S21_SET_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21_SET_HPP_

#include <initializer_list>

#include "s21_btree.hpp"
#include "s21_vector.hpp"

namespace s21 {

template <class Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = typename btree<Key, Key>::iterator;
  using const_iterator = typename btree<Key, Key>::iterator;

 protected:
  btree<Key, Key> tree;
  set(std::initializer_list<key_type> const &keys, bool is_unique_container)
      : tree(keys, keys, is_unique_container) {}

 public:
  set() : tree() {}
  explicit set(std::initializer_list<key_type> const &keys)
      : tree(keys, keys, true) {}
  set(const set<Key> &s) : tree(s.tree) {}
  set(set<Key> &&s) : tree(std::move(s.tree)) {}
  ~set() {}

  size_type size() { return tree.size(); }

  iterator begin() { return tree.begin(); }

  iterator end() { return tree.end(); }

  bool empty() { return tree.empty(); }

  size_type max_size() { return tree.max_size(); }

  void clear() { tree.clear(); }

  virtual std::pair<iterator, bool> insert(const key_type &key) {
    auto finded_key = tree.find(key);

    if (finded_key == tree.end())
      return std::pair<iterator, bool>(tree.insert(key, key), true);
    else
      return std::pair<iterator, bool>(finded_key, false);
  }

  void erase(iterator pos) { tree.erase(pos); }

  void swap(set &other) { tree.swap(other.tree); }

  void merge(set &other) { tree.merge(other.tree); }

  iterator find(const Key &key) { return tree.find(key); }

  bool contains(const Key &key) { return tree.contains(key); }

  void operator=(const set<Key> &other) { tree = other.tree; }

  void operator=(set<Key> &&other) {
    tree = other.tree;
    other.clear();
  }

  template <class... Args>
  vector<std::pair<iterator, bool>> emplace(Args &&...args) {
    vector<value_type> tmp = vector<value_type>{args...};
    vector<std::pair<iterator, bool>> ret;
    for (size_t it = 0; it < tmp.size(); ++it) {
      ret.push_back(this->insert(tmp[it]));
    }
    return ret;
  }
};

}  //  namespace s21

#endif  // S21_CONTAINERS_SRC_HEADERS_S21_SET_HPP_

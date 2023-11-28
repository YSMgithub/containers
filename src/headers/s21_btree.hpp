#ifndef S21_CONTAINERS_SRC_HEADERS_S21_BTREE_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21_BTREE_HPP_

#include <climits>
#include <initializer_list>

namespace s21 {

template <class Key, class Val>
class btree {
 public:
  using key_type = Key;
  using value_type = Val;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 private:
  size_type size_{0};
#include "../s21_btree/s21_btree_node.inc"

  btree_node *header_{nullptr};
  btree_node *first_node_{nullptr};
  btree_node *end_node_{nullptr};
  btree_node *afterend_node_{nullptr};

 public:
#include "../s21_btree/s21_btree_iterator.inc"

 public:
  btree() {}

  btree(std::initializer_list<key_type> const &keys,
        std::initializer_list<value_type> const &values,
        bool only_unique_values);

  btree(std::initializer_list<key_type> const &keys,
        std::initializer_list<value_type> const &values)
      : btree(keys, values, false) {}

  btree(const btree &s);
  btree(btree &&s);
  ~btree() { clear(); }
  void operator=(const btree<Key, Val> &s);
  void operator=(btree<Key, Val> &&s);

  size_type get_size() { return size_; }

  iterator begin();
  iterator end();
  iterator cbegin() const;
  iterator cend() const;

  bool empty();
  size_type size();
  size_type max_size();

  void clear();

  iterator insert(const key_type &key, const value_type &value);

  void erase(iterator pos);
  void swap(btree &other);
  void merge(btree &other);

  iterator find(const Key &key);
  bool contains(const Key &key);

 private:
  void clear_node(btree_node *node);
  btree_node *insert_to_subtree(const key_type &key, const value_type &value,
                                btree_node *element);
  bool contains_node_with_key(btree_node *node, const Key &key);
  iterator find_node_with_key(btree_node *node, const Key &key);
};

#include "../s21_btree/s21_btree_impl.inc"

}  //  namespace s21

#endif  // S21_CONTAINERS_SRC_HEADERS_S21_BTREE_HPP_

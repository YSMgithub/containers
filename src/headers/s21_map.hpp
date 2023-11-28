#ifndef S21_CONTAINERS_SRC_HEADERS_S21_MAP_HPP_
#define S21_CONTAINERS_SRC_HEADERS_S21_MAP_HPP_

namespace s21 {
template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
#include "../s21_map/s21_mapNode.inc"

  using Node = typename map<Key, T>::MapNode;
#include "../s21_map/s21_mapIterator.inc"

  using iterator = typename map<Key, T>::MapIterator;

  map();
  explicit map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(map &&m);
  ~map();
  map operator=(map &&m);
  T &at(const Key &key);
  T &operator[](const Key &key);

  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
  void erase(iterator pos);
  void swap(map &other);
  void merge(map &other);
  bool contains(const Key &key);

  template <class... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args &&...args);

 private:
  Node *head_;
  size_t size_;
  void copy(Node *cp);
};

template <typename Key, typename T>
map<Key, T>::map() : head_(nullptr), size_(0) {}

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const &items) : map() {
  for (const auto &element : items) {
    insert(element);
  }
}

#include "../s21_map/s21_mapMethods.inc"

}  // namespace s21

#endif  // SRC_S21_MAP_HPP_

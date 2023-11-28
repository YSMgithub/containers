template <typename T>
list<T>::list() : _size(0), head(nullptr) {}

template <typename T>
list<T>::list(size_t n) : _size(0), head(nullptr) {
  while (n != _size) {
    push_back(T());
  }
}

template <typename T>
list<T>::list(std::initializer_list<T> const &items) : list() {
  for (const auto &element : items) {
    push_back(element);
  }
}

template <typename T>
list<T>::list(const list &other) : list() {
  if (other._size) {
    list<T>::listIterator tmp(other);
    while (tmp.itr->pNext != nullptr) {
      push_back(*tmp);
      ++tmp;
    }
    push_back(*tmp);
  }
}

template <typename T>
list<T>::list(list &&other) : _size(other._size), head(other.head) {
  other.head = nullptr;
  other._size = 0;
}

template <typename T>
size_t list<T>::size() {
  return _size;
}

template <typename T>
list<T>::~list() {
  clear();
}

template <typename T>
list<T> &list<T>::operator=(list &&other) {
  clear();
  this->head = other.head;
  this->_size = other._size;
  other.head = nullptr;
  other._size = 0;
  return *this;
}

template <typename T>
size_t list<T>::max_size() {
  return std::numeric_limits<size_t>::max() / sizeof(list<T>::listNode);
}

template <typename T>
const T &list<T>::front() {
  if (!_size) throw std::out_of_range("Error, size = 0");
  return *begin();
}

template <typename T>
const T &list<T>::back() {
  if (!_size) throw std::out_of_range("Error, size = 0");
  return *last_elem();
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(*this);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  iterator tmp = last_elem();
  ++tmp;
  return tmp;
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() {
  return (const_iterator)begin();
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() {
  return (const_iterator)end();
}

template <typename T>
typename list<T>::const_iterator list<T>::clast_elem() {
  return (const_iterator)last_elem();
}

template <typename T>
bool list<T>::empty() {
  return head == nullptr;
}

template <typename T>
void list<T>::merge(list &other) {
  const_iterator tmp = cend();
  splice(tmp, other);
  sort();
}

template <typename T>
void list<T>::push_back(const T &value) {
  if (!_size) {
    head = new list<T>::listNode(value);
  } else {
    list<T>::listNode *current = head;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    current->pNext = new list<T>::listNode(value, nullptr, current);
  }
  _size++;
}

template <typename T>
void list<T>::pop_back() {
  if (!_size) return;
  if (_size == 1) {
    pop_front();
  } else {
    list<T>::listNode *current = head;
    for (size_t i = 0; i < _size - 2; i++) {
      current = current->pNext;
    }
    list<T>::listNode *tmp = current->pNext;
    current->pNext = nullptr;
    delete tmp;
    _size--;
  }
}

template <typename T>
void list<T>::push_front(const T &value) {
  if (!_size) {
    head = new list<T>::listNode(value);
  } else {
    list<T>::listNode *current = new list<T>::listNode(value, head, nullptr);
    head->pPrev = current;
    head = current;
  }
  _size++;
}

template <typename T>
void list<T>::pop_front() {
  if (!_size) return;
  list<T>::listNode *tmp = head;
  head = head->pNext;
  if (_size != 1) head->pPrev = nullptr;
  delete tmp;
  _size--;
}

template <typename T>
void list<T>::swap(list &other) {
  list<T>::listNode *tmp = head;
  head = other.head;
  other.head = tmp;
  size_t tmp_size = _size;
  _size = other._size;
  other._size = tmp_size;
}

template <typename T>
void list<T>::clear() {
  while (_size) {
    pop_front();
  }
  // this->head = nullptr;
}

template <typename T>
typename list<T>::iterator list<T>::insert(list<T>::iterator pos,
                                           const T &value) {
  if (pos == begin()) {
    push_front(value);
    pos = begin();
  } else if (pos == end()) {
    push_back(value);
    ++pos;
  } else {
    list<T>::listNode *newNode = new list<T>::listNode(value);
    newNode->pPrev = pos.itr->pPrev;
    --pos;
    newNode->pNext = pos.itr->pNext;
    pos.itr->pNext = newNode;
    ++pos;
    ++pos;
    pos.itr->pPrev = newNode;
    --pos;
    _size++;
  }
  return pos;
}

template <typename T>
void list<T>::sort() {
  if (_size > 1) {
    iterator one = begin();
    iterator two = begin();
    for (size_t i = 0; i < _size; ++i, ++one) {
      two = begin();
      size_t k = 0;
      while (k < i) {
        ++k;
        ++two;
      }
      for (size_t j = i; j < _size; ++j, ++two) {
        if (*one > *two) {
          auto tmp = *two;
          *two = *one;
          *one = tmp;
        }
      }
    }
  }
}

template <typename T>
void list<T>::unique() {
  iterator one = begin();
  iterator two = begin();
  ++two;
  while (two.itr->pNext != nullptr) {
    if (*one == *two) {
      iterator tmp = two;
      ++two;
      erase(tmp);
    } else {
      ++one;
      ++two;
    }
  }
  if (*one == *two) {
    erase(two);
  }
}

template <typename T>
void list<T>::erase(list<T>::iterator pos) {
  if (pos == begin()) {
    pop_front();
  } else if (pos.itr->pNext == nullptr) {
    pop_back();
  } else {
    iterator tmp = begin();
    ++tmp;
    iterator rab = begin();
    while (pos.itr != tmp.itr) {
      ++tmp;
      ++rab;
    }
    ++tmp;
    rab.itr->pNext = pos.itr->pNext;
    tmp.itr->pPrev = pos.itr->pPrev;
    delete pos.itr;
    _size--;
  }
}

template <typename T>
void list<T>::reverse() {
  list<T> tmp(std::move(*this));
  for (iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
    push_front(*itr);
  }
}

template <typename T>
void list<T>::splice(list<T>::const_iterator pos, list &other) {
  if (other._size == 0) {
    return;
  }
  if (pos == cbegin()) {
    list<T>::listNode *temp = head;
    head = other.head;
    iterator tmp = other.last_elem();
    tmp.itr->pNext = temp;
    temp->pPrev = tmp.itr;
  } else if (pos == cend()) {
    iterator tmp = last_elem();
    tmp.itr->pNext = other.head;
    other.head->pPrev = tmp.itr;
  } else {
    const_iterator tmp = cbegin();
    ++tmp;
    const_iterator rab = cbegin();
    while (pos.citr.itr != tmp.citr.itr) {
      ++tmp;
      ++rab;
    }
    rab.citr.itr->pNext = other.head;
    tmp = other.clast_elem();
    pos.citr.itr->pPrev = tmp.citr.itr;
    tmp.citr.itr->pNext = pos.citr.itr;
    other.head->pPrev = rab.citr.itr;
  }
  other.head = nullptr;
  _size += other._size;
  other._size = 0;
}

template <typename T>
template <class... Args>
typename list<T>::iterator list<T>::emplace(list<T>::const_iterator pos,
                                            Args &&...args) {
  iterator res = pos.citr;
  for (auto &element : {args...}) {
    res = insert(res, element);
    ++res;
  }
  --res;
  return res;
}

template <typename T>
template <class... Args>
void list<T>::emplace_back(Args &&...args) {
  for (auto &element : {args...}) {
    push_back(element);
  }
}

template <typename T>
template <class... Args>
void list<T>::emplace_front(Args &&...args) {
  for (auto &element : {args...}) {
    push_front(element);
  }
}

template <typename T>
typename list<T>::iterator list<T>::last_elem() {
  iterator tmp(*this);
  if (tmp.itr != nullptr) {
    while (tmp.itr->pNext != nullptr) {
      ++tmp;
    }
  }
  return tmp;
}
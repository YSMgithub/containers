class listIterator {
 public:
  typename list<T>::listNode *itr;

  listIterator() { itr = nullptr; }
  explicit listIterator(const list<T> &other) { itr = other.head; }
  ~listIterator() { itr = nullptr; }

  void nullptrItr() {
    if (itr == nullptr) {
      throw std::invalid_argument("Didnt work with Nullptr");
    }
  }

  T &operator*() {
    nullptrItr();
    return itr->_data;
  }

  listIterator operator++(int) {
    nullptrItr();
    listIterator ptr = *this;
    itr = itr->pNext;
    return ptr;
  }

  listIterator operator++() {
    nullptrItr();
    //   listIterator ptr = *this;
    itr = itr->pNext;
    return *this;
  }

  listIterator operator--(int) {
    nullptrItr();
    listIterator ptr = *this;
    itr = itr->pPrev;
    return ptr;
  }

  listIterator operator--() {
    nullptrItr();
    itr = itr->pPrev;
    return *this;
  }

  bool operator==(const listIterator &other) { return itr == other.itr; }

  bool operator!=(const listIterator &other) { return itr != other.itr; }
};
using iterator = typename list<T>::listIterator;

class listConstIterator {
 public:
  list::iterator citr;

  listConstIterator() {}
  explicit listConstIterator(const list<T> &other) : citr(other) {}
  explicit listConstIterator(const listIterator &other) {
    citr.itr = other.itr;
  }
  ~listConstIterator() {}

  T &operator*() { return *citr; }
  listConstIterator operator++() { return (listConstIterator)++citr; }
  listConstIterator operator++(int) { return (listConstIterator)citr++; }
  listConstIterator operator--() { return (listConstIterator)--citr; }
  listConstIterator operator--(int) { return (listConstIterator)citr--; }
  bool operator==(const listConstIterator &other) { return citr == other.citr; }
  bool operator!=(const listConstIterator &other) { return citr != other.citr; }
};
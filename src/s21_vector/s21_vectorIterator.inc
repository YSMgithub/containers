class iterator {
 public:
  T* array_;
  iterator() : array_(nullptr) {}
  explicit iterator(const vector<T>& one) { array_ = one.arr_; }
  T& operator+(int n) { return *(array_ + n); }
  T& operator-(int n) { return *(array_ - n); }
  T& operator++(int) { return *array_++; }
  T& operator--(int) { return *array_--; }
  T& operator++() { return *++array_; }
  T& operator--() { return *--array_; }

  bool operator!=(const iterator& it) { return array_ != it.array_; }
  bool operator==(const iterator& it) { return array_ == it.array_; }

  T& operator*() const { return *array_; }

  ~iterator() { array_ = nullptr; }
};

class const_iterator {
  const T* array_;
  const_iterator() : array_(nullptr) {}
  explicit const_iterator(T* one) : array_(one) {}
  T& operator+(int n) { return *(array_ + n); }
  T& operator-(int n) { return *(array_ - n); }
  T& operator=(const iterator& it) { return array_ = it; }

  T& operator++(int) { return *array_++; }
  T& operator--(int) { return *array_--; }
  T& operator++() { return *++array_; }
  T& operator--() { return *--array_; }

  bool operator!=(const iterator& it) { return array_ != it.array; }
  bool operator==(const iterator& it) { return array_ == it.array; }

  ~const_iterator() { delete[] array_; }
};
template <typename T>
template <class... Args>
void vector<T>::emplace_back(Args&&... args) {
  for (auto& elem : {args...}) {
    push_back(elem);
  }
}

template <typename T>
template <class... Args>
typename vector<T>::iterator vector<T>::emplace(const_iterator pos,
                                                Args&&... args) {
  iterator res = pos.citr;
  for (auto& element : {args...}) {
    res = insert(res, element);
    ++res;
  }
  --res;
  return res;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(vector<T>::iterator pos,
                                               const T& value) {
  T* newarr = new T[size_ + 1];
  size_t count = 0;
  for (; pos != begin(); count++, --pos) {
  }
  newarr[count] = value;
  for (size_t i = 0; i < size_; i++) {
    if (i < count) {
      newarr[i] = arr_[i];
    } else {
      newarr[i + 1] = arr_[i];
    }
  }
  delete[] arr_;
  arr_ = newarr;
  size_++;
  capacity_ = size_;
  pos = begin();
  while (count) {
    count--;
    ++pos;
  }
  return pos;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    T* newarr = new T[size_];
    for (size_t i = 0; i < size_; i++) {
      newarr[i] = arr_[i];
    }
    delete[] arr_;
    arr_ = newarr;
    capacity_ = size_;
  }
}

template <typename T>
void vector<T>::erase(vector<T>::iterator pos) {
  size_t count;
  for (count = 0; pos != begin(); count++, --pos) {
  }
  for (size_t i = count; i < size_; ++i) {
    arr_[i] = arr_[i + 1];
  }
  --size_;
}

template <typename T>
vector<T> vector<T>::operator=(vector<T>&& a) {
  delete[] arr_;
  size_ = a.size_;
  capacity_ = a.capacity_;
  arr_ = a.arr_;
  a.size_ = 0;
  a.capacity_ = 0;
  a.arr_ = nullptr;
  return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(*this);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  iterator vec_iterator = begin();
  for (size_t i = 0; i != size_; i++) {
    ++vec_iterator;
  }
  ++vec_iterator;
  return vec_iterator;
}

template <typename T>
bool vector<T>::empty() {
  return size_ == 0;
}

template <typename T>
vector<T>::~vector() {
  clear();
}

template <typename T>
void vector<T>::clear() {
  if (arr_) {
    size_ = 0;
    capacity_ = 0;
    delete[] arr_;
    arr_ = nullptr;
  }
}

template <typename T>
vector<T>::vector() : arr_(nullptr), size_(0), capacity_(0) {}

template <typename T>
vector<T>::vector(size_type n) : size_(n), capacity_(n) {
  arr_ = new T[n];
}

template <typename T>
vector<T>::vector(const vector& v) : size_(v.size_), capacity_(v.capacity_) {
  arr_ = new T[v.size_];
  for (size_t i = 0; i < size_; i++) {
    arr_[i] = v.arr_[i];
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<T> const& items)
    : arr_(nullptr), size_(0), capacity_(0) {
  for (auto& elem : items) {
    push_back(elem);
  }
  shrink_to_fit();
}

template <typename T>
vector<T>::vector(vector&& v)
    : arr_(v.arr_), size_(v.size_), capacity_(v.capacity_) {
  for (size_t i = 0; i < size_; i++) {
    arr_[i] = v.arr_[i];
  }
  v.size_ = 0;
  v.capacity_ = 0;
  v.arr_ = nullptr;
}

template <typename T>
T& vector<T>::operator[](size_type pos) {
  return arr_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::at(typename vector<T>::size_type pos) {
  if (pos > size_) {
    throw std::out_of_range("terminate called after throwing an instance of ");
  }
  return arr_[pos];
}

template <typename T>
typename vector<T>::iterator vector<T>::data() {
  return begin();
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  return arr_[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() {
  return arr_[size_ - 1];
}

template <typename T>
typename vector<T>::size_type vector<T>::size() {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return (std::numeric_limits<size_type>::max() / sizeof(T*));
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (!size) size = 1;
  if (size <= capacity_) {
  } else {
    T* newarr = new T[size];
    for (size_t i = 0; i < size_; i++) {
      newarr[i] = arr_[i];
    }
    delete[] arr_;
    arr_ = newarr;
    capacity_ = size;
  }
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (capacity_ == size_) {
    reserve(2 * size_);
  }
  arr_[size_] = value;
  ++size_;
}

template <typename T>
void vector<T>::pop_back() {
  --size_;
}

template <typename T>
void vector<T>::swap(vector& other) {
  auto size = size_;
  auto capacity = capacity_;
  auto arr = arr_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  arr_ = other.arr_;
  other.size_ = size;
  other.capacity_ = capacity;
  other.arr_ = arr;
}
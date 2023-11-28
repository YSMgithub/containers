class MapIterator {
 public:
  Node *first_;
  Node *end_;
  Node *itr_;
  Node *itrhead_;
  MapIterator() : first_(), end_(), itr_(), itrhead_() {}
  explicit MapIterator(const map<Key, T> &one) {
    if (one.head_->left_) {
      first_ = one.head_->left_;
      while (first_->left_) {
        first_ = first_->left_;
      }
    } else {
      first_ = one.head_;
    }
    if (one.head_->right_) {
      end_ = one.head_->right_;
      while (end_->right_) {
        end_ = end_->right_;
      }
    } else {
      end_ = one.head_;
    }
    itr_ = first_;
    itrhead_ = one.head_;
  }

  MapIterator operator++() {
    if (itr_ == end_) {
      itr_ = end_->right_;
      return *this;
    }
    Node *tmp = itr_;
    while (!tmp->right_) {
      tmp = tmp->parent_;
      if (itr_->key_ < tmp->key_) {
        itr_ = tmp;
        return *this;
      }
    }
    while (tmp->key_ < itr_->key_) {
      tmp = tmp->parent_;
      if (itr_->key_ < tmp->key_) {
        itr_ = tmp;
        return *this;
      }
    }
    tmp = tmp->right_;
    while (tmp->left_) {
      tmp = tmp->left_;
    }
    itr_ = tmp;
    return *this;
  }

  MapIterator operator--() {
    if (itr_ == end_->right_) {
      itr_ = end_;
      return *this;
    }
    Node *tmp = itr_;
    while (!tmp->left_) {
      tmp = tmp->parent_;
      if (itr_->key_ > tmp->key_) {
        itr_ = tmp;
        return *this;
      }
    }
    while (tmp->key_ > itr_->key_) {
      tmp = tmp->parent_;
      if (itr_->key_ > tmp->key_) {
        itr_ = tmp;
        return *this;
      }
    }
    tmp = tmp->left_;
    while (tmp->right_) {
      tmp = tmp->right_;
    }
    itr_ = tmp;
    return *this;
  }

  bool operator!=(const MapIterator &it) { return itr_ != it.itr_; }
  bool operator==(const MapIterator &it) { return itr_ == it.itr_; }

  std::pair<Key, T> operator*() const {
    return std::make_pair(itr_->key_, itr_->value_);
  }

  ~MapIterator() {
    first_ = nullptr;
    end_ = nullptr;
    itr_ = nullptr;
  }
};
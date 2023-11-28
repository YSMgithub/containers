class MapNode {
 public:
  Key key_;
  T value_;
  MapNode *left_;
  MapNode *right_;
  MapNode *parent_;

  MapNode()
      : key_(), value_(), left_(nullptr), right_(nullptr), parent_(nullptr) {}
  explicit MapNode(Key const &key = Key(), T const &value = T(),
                   MapNode *left = nullptr, MapNode *right = nullptr,
                   MapNode *parent = nullptr)
      : key_(key), value_(value), left_(left), right_(right), parent_(parent) {}
  ~MapNode() {
    left_ = nullptr;
    right_ = nullptr;
    parent_ = nullptr;
  }
};
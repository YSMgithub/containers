class listNode {
 public:
  T _data;
  listNode *pNext;
  listNode *pPrev;

  listNode() {}

  explicit listNode(T const &_data = T(), listNode *pNext = nullptr,
                    listNode *pPrev = nullptr) {
    this->_data = _data;
    this->pNext = pNext;
    this->pPrev = pPrev;
  }

  ~listNode() {
    pNext = nullptr;
    pPrev = nullptr;
  };
};
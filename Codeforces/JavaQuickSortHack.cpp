//
// Author: halyavin (https://codeforces.com/contest/817/hacks/329192/test)
//

#include <bits/stdc++.h>

template<class T1, class T2>
struct CasePointer {
  uintptr_t value = reinterpret_cast<uintptr_t>((T1*) nullptr);
  T1* operator()() const {
    return reinterpret_cast<T1*>(value);
  }
  T1& operator*() const {
    return *operator()();
  }
  T1* operator->() const {
    return operator()();
  }
  bool isOther() const {
    return (value & 1) != 0;
  }
  T2* other() {
    return reinterpret_cast<T2*>(value & ~uintptr_t(1));
  }
  const T2* other() const {
    return reinterpret_cast<const T2*>(value & ~uintptr_t(1));
  }
  void operator=(T1* other) {
    value = reinterpret_cast<uintptr_t>(other);
  }
  void operator=(T2* other) {
    value = reinterpret_cast<uintptr_t>(other) + 1;
  }

  bool operator==(const CasePointer& other) const {
    return value == other.value;
  }

  bool operator!=(const CasePointer& other) const {
    return value != other.value;
  }
};

template<class T>
class TreapList {
  struct Node {
    T value;
    uint32_t weight;
    uint32_t size = 1;
    CasePointer<Node, TreapList> parent;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(const T& value, uint32_t weight)
        : value(value), weight(weight) {
    }
    Node(T&& value, uint32_t weight)
        : value(std::move(value)), weight(weight) {
    }
    bool hasParent() const {
      return !parent.isOther();
    }
  };
  template<bool isConst = false>
  struct IterImpl {
    friend class IterImpl;
    friend class TreapList;
   private:
    CasePointer<Node, TreapList> pos;

   public:
    IterImpl() {
    }

    IterImpl(Node* node) {
      pos = node;
    }
    IterImpl(TreapList* rootObject) {
      pos = rootObject;
    }
    IterImpl(TreapList* rootObject, uint32_t index) {
      pos = rootObject->root;
      if (pos->left != nullptr) {
        *this += int32_t(index - pos->left->size);
      } else {
        *this += int32_t(index);
      }
    }
    template<bool isOtherConst>
    bool operator==(const IterImpl<isOtherConst>& other) const {
      return pos == other.pos;
    }
    template<bool isOtherConst>
    bool operator!=(const IterImpl<isOtherConst>& other) const {
      return pos != other.pos;
    }
    template<bool isOtherConst, class = std::enable_if_t<isConst || !isOtherConst>>
    void operator=(const IterImpl<isOtherConst>& other) {
      pos = other.pos;
    }
    std::conditional_t<isConst, const T&, T&> operator*() const {
      return pos->value;
    }
    std::conditional_t<isConst, const T*, T*> operator->() const {
      return &pos->value;
    }
    IterImpl& operator++() {
      if (pos.isOther()) {
        // Undefined Behaviour
        return *this;
      }
      if (pos->right != nullptr) {
        pos = getFirstVertex(pos->right);
        return *this;
      }
      while (true) {
        if (!pos->hasParent()) {
          pos = pos->parent.other();
          return *this;
        }
        Node* parent = pos->parent();
        if (parent->left == pos()) {
          pos = parent;
          return *this;
        }
        pos = parent;
      }
    }

    IterImpl& operator--() {
      if (pos.isOther()) {
        pos = getLastVertex(pos.other()->root);
        return *this;
      }
      if (pos->left != nullptr) {
        pos = getLastVertex(pos->left);
        return *this;
      }
      while (true) {
        if (!pos->hasParent()) {
          // Undefined behaviour.
          return *this;
        }
        Node* parent = pos->parent();
        if (parent->right == pos()) {
          pos = parent;
          return *this;
        }
        pos = parent;
      }
    }

    uint32_t index() const {
      if (pos.isOther()) {
        Node* root = pos.other()->root;
        if (root == nullptr) {
          return 0;
        }
        return root->size;
      }
      Node* node = pos();
      uint32_t result = node->left ? node->left->size : 0;
      while (node->hasParent()) {
        Node* parent = node->parent();
        if (parent->left != nullptr) {
          result += parent->left->size;
        }
        node = parent;
      }
      return result;
    }

    IterImpl& operator+=(int32_t value) {
      if (pos.isOther()) {
        if (value >= 0) {
          return *this;
        }
        pos = pos.other()->root;
        value++;
        if (pos->right != nullptr) {
          value += pos->right->size;
        }
      }
      while (value != 0) {
        if (pos->left != nullptr && value < 0) {
          pos = pos->left;
          value++;
          if (pos->right != nullptr) {
            value += pos->right->size;
          }
          continue;
        }
        if (pos->right != nullptr && value > 0) {
          pos = pos->right;
          value--;
          if (pos->left != nullptr) {
            value -= pos->left->size;
          }
          continue;
        }
        if (!pos->hasParent()) {
          pos = pos->parent.other();
          return *this;
        }
        if (value > 0) {
          bool good = false;
          while (pos->hasParent()) {
            Node* parent = pos->parent();
            if (parent->left == pos()) {
              value--;
              pos = parent;
              good = true;
              break;
            }
            pos = parent;
          }
          if (!good) {
            pos = pos->parent.other();
            return *this;
          }
        } else {
          bool good = false;
          while (pos->hasParent()) {
            Node* parent = pos->parent();
            if (parent->right == pos()) {
              value++;
              pos = parent;
              good = true;
              break;
            }
            pos = parent;
          }
          if (!good) {
            pos = pos->parent.other();
            return *this;
          }
        }
      }
      return *this;
    }

    IterImpl& operator-=(int32_t value) {
      return *this += -value;
    }

    IterImpl operator+(int32_t value) {
      IterImpl result(*this);
      result += value;
      return result;
    }

    IterImpl operator-(int32_t value) {
      IterImpl result(*this);
      result -= value;
      return result;
    }
  };

  Node* root = nullptr;
  std::ranlux48 rnd;

  static Node* getFirstVertex(Node* current) {
    if (current == nullptr) {
      return nullptr;
    }
    while (current->left != nullptr) current = current->left;
    return current;
  }

  static Node* getLastVertex(Node* current) {
    if (current == nullptr) {
      return nullptr;
    }
    while (current->right != nullptr) current = current->right;
    return current;
  }

  static uint64_t rnd64() {
    uint32_t res1, res2;
#ifdef __MINGW32__
    asm volatile("rdrand %0" :"=a"(res1) ::"cc");
    asm volatile("rdrand %0" :"=a"(res2) ::"cc");
#else
    {
      std::random_device device;
      res1 = device();
      res2 = device();
    }
#endif
    return (uint64_t(res1) << 32) + res2;
  }

  Node* createNode(const T& value) {
    return new Node(value, uint32_t(rnd()));
  }

  Node* createNode(T&& value) {
    return new Node(std::move(value), uint32_t(rnd()));
  }

  void freeNodes(Node* node) {
    if (node->left != nullptr) {
      freeNodes(node->left);
    }
    if (node->right != nullptr) {
      freeNodes(node->right);
    }
    delete node;
  }

  void push_back_node(Node* node) {
    if (root == nullptr) {
      root = node;
      root->parent = this;
      node->size = 1;
      return;
    }
    if (node->weight > root->weight) {
      node->left = root;
      root->parent = node;
      node->parent = this;
      node->size = root->size + 1;
      root = node;
      return;
    }
    Node* cur = root;
    while (cur->right != nullptr) {
      cur->size++;
      Node* right = cur->right;
      if (node->weight > right->weight) {
        cur->right = node;
        node->parent = cur;
        node->left = right;
        node->size = right->size + 1;
        right->parent = node;
        return;
      }
      cur = cur->right;
    }
    cur->right = node;
    cur->size++;
    node->parent = cur;
    node->size = 1;
  }

  void push_front_node(Node* node) {
    if (root == nullptr) {
      root = node;
      root->parent = this;
      node->size = 1;
      return;
    }
    if (node->weight > root->weight) {
      node->right = root;
      root->parent = node;
      node->parent = this;
      node->size = root->size + 1;
      root = node;
      return;
    }
    Node* cur = root;
    while (cur->left != nullptr) {
      cur->size++;
      Node* left = cur->left;
      if (node->weight > left->weight) {
        cur->left = node;
        node->parent = cur;
        node->right = left;
        node->size = left->size + 1;
        left->parent = node;
        return;
      }
      cur = cur->left;
    }
    cur->left = node;
    cur->size++;
    node->parent = cur;
    node->size = 1;
  }

  void moveParent(Node* from, Node* to) {
    to->parent = from->parent;
    if (to->parent.isOther()) {
      root = to;
      return;
    }
    if (from->parent->right == from) {
      from->parent->right = to;
    } else {
      from->parent->left = to;
    }
  }

  void balanceDown(Node* node) {
    // node->right must be nullptr
    // node->parent is normal
    while (node->left != nullptr && node->left->weight > node->weight) {
      Node* parent = node->parent();
      Node* left = node->left;
      node->left = left->right;
      left->size = node->size;
      node->size = 1;
      if (node->left != nullptr) {
        node->size += node->left->size;
      }
      if (node->left != nullptr) {
        node->left->parent = node;
      }
      left->right = node;
      moveParent(node, left);
      node->parent = left;
    }
  }

  void rotateLeft(Node* parent) {
    Node* node = parent->right;
    parent->right = node->left;
    node->size = parent->size;
    parent->size = 1;
    if (parent->right != nullptr) {
      parent->right->parent = parent;
      parent->size += parent->right->size;
    }
    if (parent->left != nullptr) {
      parent->size += parent->left->size;
    }
    moveParent(parent, node);
    parent->parent = node;
    node->left = parent;
  }

  void rotateRight(Node* parent) {
    Node* node = parent->left;
    parent->left = node->right;
    node->size = parent->size;
    parent->size = 1;
    if (parent->left != nullptr) {
      parent->left->parent = parent;
      parent->size += parent->left->size;
    }
    if (parent->right != nullptr) {
      parent->size += parent->right->size;
    }
    moveParent(parent, node);
    parent->parent = node;
    node->right = parent;
  }

  void balanceUp(Node* node) {
    while (!node->parent.isOther() && node->parent->weight < node->weight) {
      Node* parent = node->parent();
      parent->size++;
      if (parent->right == node) {
        rotateLeft(parent);
      } else {
        rotateRight(parent);
      }
    }
    while (!node->parent.isOther()) {
      node = node->parent();
      node->size++;
    }
  }

  template<bool isConst>
  void insert(IterImpl<isConst> it, Node* node) {
    if (it.pos.isOther()) {
      push_back_node(node);
      return;
    }
    Node* cur = it.pos();
    if (node->weight <= cur->weight) {
      node->parent = cur;
      node->size = 1;
      node->left = cur->left;
      if (cur->left != nullptr) {
        node->size += cur->left->size;
        cur->left->parent = node;
      }
      cur->left = node;
      cur->size++;
      balanceDown(node);
      while (!cur->parent.isOther()) {
        cur = cur->parent();
        cur->size++;
      }
      return;
    } else {
      node->left = cur->left;
      if (cur->left != nullptr) {
        cur->left->parent = node;
      }
      node->right = cur;
      node->parent = cur->parent;
      cur->parent = node;
      node->size = cur->size + 1;
      cur->left = nullptr;
      cur->size = 1;
      if (cur->right != nullptr) {
        cur->size += cur->right->size;
      }
      if (node->parent.isOther()) {
        root = node;
      } else {
        if (node->parent->right == cur) {
          node->parent->right = node;
        } else {
          node->parent->left = node;
        }
      }
      balanceUp(node);
      return;
    }
  }

 public:
  TreapList(uint64_t seed) : rnd(seed) {
  }
  TreapList() : rnd(rnd64()) {
  }

  ~TreapList() {
    clear();
  }

  using Iterator = IterImpl<false>;
  using ConstIterator = IterImpl<true>;

  void clear() {
    if (root != nullptr) {
      freeNodes(root);
    }
    root = nullptr;
  }

  Iterator begin() {
    return root ? Iterator(getFirstVertex(root)) : Iterator(this);
  }

  ConstIterator begin() const {
    return root ? ConstIterator(getFirstVertex(root)) : ConstIterator(const_cast<TreapList*>(this));
  }

  ConstIterator cbegin() const {
    return root ? ConstIterator(getFirstVertex(root)) : ConstIterator(const_cast<TreapList*>(this));
  }

  Iterator end() {
    return Iterator(this);
  }

  ConstIterator end() const {
    return ConstIterator(const_cast<TreapList*>(this));
  }

  ConstIterator cend() const {
    return ConstIterator(const_cast<TreapList*>(this));
  }

  uint32_t size() const {
    if (root == nullptr) {
      return 0;
    }
    return root->size;
  }

  Iterator get(uint32_t index) {
    return Iterator(this, index);
  }

  ConstIterator get(uint32_t index) const {
    return ConstIterator(const_cast<TreapList*>(this), index);
  }

  T& operator[](uint32_t index) {
    return *get(index);
  }

  const T& operator[](uint32_t index) const {
    return *get(index);
  }
  void push_back(const T& value) {
    push_back_node(createNode(value));
  }
  void push_back(T&& value) {
    push_back_node(createNode(std::move(value)));
  }
  void push_front(const T& value) {
    push_front_node(createNode(value));
  }
  void push_front(T&& value) {
    push_front_node(createNode(std::move(value)));
  }
  void insert(Iterator pos, const T& value) {
    insert(pos, createNode(value));
  }
  void insert(Iterator pos, T&& value) {
    insert(pos, createNode(std::move(value)));
  }
  void insert(ConstIterator pos, const T& value) {
    insert(pos, createNode(value));
  }
  void insert(ConstIterator pos, T&& value) {
    insert(pos, createNode(std::move(value)));
  }
  template<bool isConst>
  void erase(IterImpl<isConst> it) {
    if (it.pos.isOther()) {
      return;
    }
    Node* cur = it.pos();
    while (cur->left != nullptr || cur->right != nullptr) {
      if (cur->left != nullptr && (cur->right == nullptr || cur->left->weight >= cur->right->weight)) {
        rotateRight(cur);
      } else {
        rotateLeft(cur);
      }
    }
    if (cur->parent.isOther()) {
      delete cur;
      root = nullptr;
    } else {
      if (cur->parent->right == cur) {
        cur->parent->right = nullptr;
      } else {
        cur->parent->left = nullptr;
      }
      Node* tmp = cur->parent();
      delete cur;
      cur = tmp;
      cur->size--;
      while (!cur->parent.isOther()) {
        cur->parent->size--;
        cur = cur->parent();
      }
    }
  }

  void check(Node* node) {
    uint32_t size = 1;
    if (node->left != nullptr) {
      check(node->left);
      if (node->weight < node->left->weight) {
        std::cerr << "check3" << std::endl;
      }
      if (node->left->parent.isOther() || node->left->parent() != node) {
        std::cerr << "check6" << std::endl;
      }
      size += node->left->size;
    }
    if (node->right != nullptr) {
      check(node->right);
      if (node->weight < node->right->weight) {
        std::cerr << "check4" << std::endl;
      }
      if (node->right->parent.isOther() || node->right->parent() != node) {
        std::cerr << "check7" << std::endl;
      }
      size+= node->right->size;
    }
    if (size != node->size) {
      std::cerr << "check5" << std::endl;
    }
  }
  void check() {
    if (root != nullptr) {
      check(root);
      if (!root->parent.isOther()) {
        std::cerr << "check1" << std::endl;
      }
      if (root->parent.other() != this) {
        std::cerr << "check2" << std::endl;
      }
    }
  }
};

struct Generator {
  TreapList<int> tree;
  using It = TreapList<int>::Iterator;
  std::vector<int> result;
  int left, right;
  It itLeft, itRight;
  int e1, e2, e3, e4, e5;
  std::array<It, 5> its;

  void downIteration() {
    auto leftCopy = itLeft;
    std::array<int, 4> ts;
    for (int i = 0; i < 4; i++) {
      int& v = *leftCopy;
      ++leftCopy;
      ts[i] = v;
      result[*its[i]] = left + i;
      v = *its[i];
    }
    *its[0] = ts[2];
    *its[1] = ts[0];
    *its[2] = ts[1];
    int last = *itRight;
    *itRight = ts[3];
    *its[3] = last;
    left += 4;
    itLeft = leftCopy;
  }

  void upIteration() {
    auto rightCopy = itRight;
    int& v1 = *rightCopy;
    int t1 = v1;
    v1 = *its[4];
    result[v1] = right;
    --rightCopy;
    int& v2 = *rightCopy;
    int t2 = v2;
    v2 = *its[3];
    result[v2] = right - 1;
    --rightCopy;
    int& v3 = *rightCopy;
    int t3 = v3;
    v3 = *its[2];
    result[v3] = right - 2;
    int v4 = *its[1];
    result[v4] = right - 3;

    *its[1] = *itLeft;
    *its[3] = t1;
    *its[4] = t2;
    *itLeft = t3;
    tree.erase(its[2]);
    tree.insert(rightCopy, v4);
    --rightCopy;
    --rightCopy;
    right -= 4;
    itRight = rightCopy;
  }

  void genEq(std::ostream& out, int n) {
    tree.clear();
    for (int i = 0; i < n; i++) {
      tree.push_back(i);
    }
    result.resize(n);
    std::fill(result.begin(), result.end(), -2);
    for (int i = 0; i < 67; i++) {
      result[2 * i] = -3;
      result[2 * i + 1] = -1;
    }
    left = 0;
    right = n - 1;
    itLeft = tree.begin();
    itRight = tree.end() - 1;
    int value = 0;
    while (right - left >= 47) {
      int len = right - left + 1;
      int s = (len >> 3) + (len >> 6) + 1;
      e3 = (left + right) / 2;
      e2 = e3 - s;
      e1 = e2 - s;
      e4 = e3 + s;
      e5 = e4 + s;
      its = {tree.get(e1), tree.get(e2), tree.get(e3), tree.get(e4), tree.get(e5)};
      for (size_t i = 0; i < 5; i++) {
        int idx = *its[i];
        if (result[idx] == -3) {
          if (result[idx + 1] >= 0 && (idx == 0 || result[idx - 1] >= 0)) {
            result[idx] = -2;
          }
        }
      }
      for (size_t i = 0; i < 5; i++) {
        for (size_t j = i + 1; j < 5; j++) {
          if (result[*its[i]] > result[*its[j]]) {
            std::swap(*its[i], *its[j]);
          }
        }
      }
      if (result[*its[2]] < -2) {
        break;
      }
      result[*its[2]] = value;
      result[*its[3]] = value;
      result[*its[4]] = value;
      value++;
      int v1 = *its[2];
      int v2 = *its[3];
      int v3 = *its[4];
      tree.erase(its[2]);
      tree.erase(its[3]);
      tree.erase(its[4]);
      auto ins = itRight + 1;
      tree.insert(ins, v1);
      tree.insert(ins, v2);
      tree.insert(ins, v3);
      right -= 3;
    }
    for (int marker = -1; marker >= -3; marker--)
    {
      auto it = itLeft;
      for (int i = left; i <= right; i++) {
        if (result[*it] == marker) {
          result[*it] = value;
        }
        ++it;
      }
      value++;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      result[i] = value - result[i];
      if (result[i] > mx) mx = result[i];
    }
    out << "1\n" << n << "\n";
    for (int i = 0; i < n; ++i) {
      if (i) out << " ";
      out << result[i] + 1;
    }
    out << '\n';
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  //output format can be changed a few lines up
  int length_of_hack=2e5;
  Generator().genEq(std::cout, length_of_hack); //let this be the array length
  return 0;
}
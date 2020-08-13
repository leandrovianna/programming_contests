// URI - Surf Aquático - 2560
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SplayTree {
  template <typename U>
  struct Node {
    U key;
    Node *left, *right;
    Node *parent;
    int count;

    Node(U key) :
      key(key), left(nullptr), right(nullptr), parent(nullptr), count(1) {}
    ~Node() {
      if (left != nullptr)
        delete left;

      if (right != nullptr)
        delete right;
    }

    void copy(const Node<U>& node) {
      this->key = node.key;
      this->count = node.count;
    }
  };

  Node<T> *root;
  static const int SPLAY_HEIGHT = 100;

  bool isLeftChild(const Node<T> *const node) const {
    assert(node->parent != nullptr);
    return node->key < node->parent->key;
  }

  void rotateLeft(Node<T> *node) {
    auto q = node->right;
    assert(q != nullptr);
    node->right = q->left;
    if (q->left != nullptr)
      q->left->parent = node;
    q->left = node;
    if (node->parent != nullptr) {
      if (isLeftChild(node))
        node->parent->left = q;
      else
        node->parent->right = q;
    }
    q->parent = node->parent;
    node->parent = q;
  }

  void rotateRight(Node<T> *node) {
    auto q = node->left;
    assert(q != nullptr);
    node->left = q->right;
    if (q->right != nullptr)
      q->right->parent = node;
    q->right = node;
    if (node->parent != nullptr) {
      if (isLeftChild(node))
        node->parent->left = q;
      else
        node->parent->right = q;
    }
    q->parent = node->parent;
    node->parent = q;
  }

  void splay(Node<T> *node) {
    if (node == nullptr) return;

    while (node->parent != nullptr) {
      // parent of node
      auto p = node->parent;
      // grandparent of node
      auto g = p->parent;

      if (g == nullptr) {
        // zig operation
        if (isLeftChild(node)) {
          rotateRight(p);
        } else {
          rotateLeft(p);
        }
      } else if (isLeftChild(node) && isLeftChild(p)) {
        // zig-zig operation
        rotateRight(g);
        rotateRight(p);
      } else if (isLeftChild(node)) {
        // zig-zag operation
        rotateRight(p);
        rotateLeft(g);
      } else if (isLeftChild(p)) {
        // zig-zag operation
        rotateLeft(p);
        rotateRight(g);
      } else {
        // zig-zig operation
        rotateLeft(g);
        rotateLeft(p);
      }
    }

    // change root to node
    root = node;
  }

  Node<T> *minNode(Node<T> *node) {
    assert(node != nullptr);
    Node<T> *parent = nullptr;
    while (node != nullptr) {
      parent = node;
      node = node->left;
    }
    return parent;
  }

  Node<T> *maxNode(Node<T> *node) {
    assert(node != nullptr);
    Node<T> *parent = nullptr;
    while (node != nullptr) {
      parent = node;
      node = node->right;
    }
    return parent;
  }

  void printNode(Node<T> *node, int space = 0) const {
    cout << string(space, ' ');
    if (node == nullptr) cout << "X" << endl;
    else {
      cout << node->key << "(" << node->count << ")"<< endl;
      printNode(node->left, space+1);
      printNode(node->right, space+1);
    }
  }

  public:
  SplayTree() : root(nullptr) {
  }
  ~SplayTree() {
    if (root != nullptr)
      delete root;
  }

  void insert(T key) {
    if (root == nullptr) {
      root = new Node<T>(key);
      return;
    }

    Node<T> *node = root, *parent = nullptr;
    int h = 0;
    while (node != nullptr) {
      h++;
      parent = node;

      if (key < node->key) {
        node = node->left;
      } else if (node->key < key) {
        node = node->right;
      } else {
        // Key repeated, increase count
        node->count++;
        break;
      }
    }

    if (node == nullptr) {
      node = new Node<T>(key);
      node->parent = parent;

      if (key < parent->key) {
        parent->left = node;
      } else {
        parent->right = node;
      }
    }

    if (h > SPLAY_HEIGHT)
      splay(node);
  }

  void erase(T key) {
    Node<T> *node = root, *parent = nullptr;
    int h = 0;
    while (node != nullptr) {
      h++;
      if (key < node->key) {
        parent = node;
        node = node->left;
      } else if (node->key < key) {
        parent = node;
        node = node->right;
      } else if (node->count > 1) {
        // More than one for this key, descrease count
        node->count--;
        node = nullptr;
      } else if (node->right == nullptr) {
        if (parent == nullptr) {
          root = node->left;
        } else if (node->key < parent->key) {
          parent->left = node->left;
        } else {
          parent->right = node->left;
        }

        if (node->left != nullptr)
          node->left->parent = parent;

        node->left = nullptr;
        delete node;
        node = nullptr;
      } else {
        Node<T> *tmp = minNode(node->right);
        node->copy(*tmp);
        tmp->count = 1;

        key = tmp->key; // change the key to delete
        parent = node;
        node = node->right; // continue search
      }
    }

    if (parent == nullptr) return;

    if (h > SPLAY_HEIGHT)
     splay(parent);
  }

  T min() {
    auto node = minNode(root);
    splay(node);
    return node->key;
  }

  T max() {
    auto node = maxNode(root);
    splay(node);
    return node->key;
  }

  void print() const {
    printNode(root);
  }
};

const int N = 200100;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, b;

  while (cin >> n >> b) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    SplayTree<int> values;

    int sum = 0;
    for (int i = 0; i < b; i++) {
      sum += a[i];
      values.insert(a[i]);
    }

    int64_t ans = 0;
    for (int i = 0, j = b-1; j < n; i++, j++) {
      int minimum = values.min();
      int maximum = values.max();
      ans += sum - minimum - maximum;

      values.erase(a[i]);
      sum -= a[i];

      values.insert(a[j+1]);
      sum += a[j+1];
    }

    cout << ans << "\n";
  }
  return 0;
}

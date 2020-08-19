// URI - Conjuntos Bons e Ruins - 2087
#include <bits/stdc++.h>
using namespace std;

struct Node {
  // Alphabet Size
  static const int E = 26;

  bool isEnd;
  int numberChildren;
  Node *children[E];

  Node() : isEnd(false), numberChildren(0) {
    for (int e = 0; e < E; e++)
      children[e] = nullptr;
  }
  ~Node() {
    for (int e = 0; e < E; e++)
      if (children[e] != nullptr)
        delete children[e];
  }
};

class Trie {
  /*
   * Get the unique index of each characther supported
   */
  int charId(char ch) {
    if (ch < 'a' || ch > 'z')
      throw runtime_error("Character not supported.");

    return ch - 'a';
  }

  Node *const root;
  bool foundPrefix;

  public:
  Trie() : root(new Node()), foundPrefix(false) {}
  ~Trie() {
    delete root;
  }

  void insert(const string &word);
  bool hasPrefix() const;
};

void Trie::insert(const string &word) {
  Node *node = root;
  for (const auto &ch : word) {
    int index = charId(ch);

    if (node->children[index] == nullptr) {
      node->children[index] = new Node();
      node->numberChildren++;
    }

    node = node->children[index];

    // word is already in trie or contains a prefix already in trie
    if (node->isEnd)
      foundPrefix = true;
  }

  // word is prefix of some other word
  if (node->numberChildren > 0)
    foundPrefix = true;

  node->isEnd = true;
}

bool Trie::hasPrefix() const {
  return foundPrefix;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  string word;

  while (cin >> n, n) {
    auto trie = Trie();

    bool isBad = false;

    for (int i = 0; i < n; i++) {
      cin >> word;
      if (!isBad)
        trie.insert(word);

      isBad = isBad || trie.hasPrefix();
    }

    if (isBad)
      cout << "Conjunto Ruim\n";
    else
      cout << "Conjunto Bom\n";
  }
  return 0;
}

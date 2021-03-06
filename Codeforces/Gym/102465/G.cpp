// Codeforces - Strings - 102465G
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

class Rope {
  const Rope *left, *right;
  int64_t len; // length of the string
  int64_t w; // length of the left child's string 

  string data;
  int sum;
  
  public:
  Rope() {
    len = w = sum = 0;
    data = "";
    left = right = nullptr;
  }

  Rope(string data) : data(data) {
    sum = 0;
    for (const auto &ch : data) {
      sum += ch;
      sum %= MOD;
    }
    len = w = data.size();
    left = right = nullptr;
  }

  Rope(const Rope *left, const Rope *right) {
    this->left = left;
    this->right = right;
    this->len = 0;
    this->w = 0;
    this->sum = 0;

    if (this->left) {
      this->len += this->left->len;
      this->w = this->left->len;
      sum = (sum + left->sum) % MOD;
    }

    if (this->right) {
      this->len += this->right->len;
      sum = (sum + right->sum) % MOD;
    }
  }

  bool isLeaf() const {
    return left == nullptr && right == nullptr;
  }

  const Rope* copy(int i, int j) const {
    return new Rope(data.substr(i, j - i + 1));
  }

  const Rope* copy() const {
    return new Rope(data);
  }

  const Rope* substr(int64_t i, int64_t j) const {
    if (i > j) return new Rope();

    if (i == 0 && j == this->len-1) {
      if (isLeaf())
        return copy();
      else
        return new Rope(left, right);
    }

    if (isLeaf()) {
      return copy(i, j);
    }

    const Rope *l = nullptr, *r = nullptr;

    if (i < w && left) {
      l = left->substr(i, min(w-1, j));      
    }

    if (w <= j && right) {
      r = right->substr(max(i - w, int64_t{0}), j - w);
    }

    return new Rope(l, r);
  }

  int report() const {
      return sum;
  }

  int64_t size() const {
    return len;
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<const Rope*> roots;
  roots.push_back(new Rope(s));

  int64_t lo, hi;
  for (int i = 1, x, y; i < n; i++) {
    cin >> s;
    if (s == "SUB") {
      cin >> x >> lo >> hi;
      roots.push_back(roots[x]->substr(lo, hi-1));
    } else {
      cin >> x >> y;
      roots.push_back(new Rope(roots[x], roots[y]));
    }
  }

  cout << roots[n-1]->report() << "\n";

  return 0;
}

// Codeforces - Strings - 102465G
// This solution use shared_ptr
// Needs remove Ropes to pass Memory Limit (256MB)
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

class Rope {
  shared_ptr<const Rope> left, right;
  int64_t len; // length of the string
  int64_t w; // length of the left child's string 

  string data;
  int sum;
  
  public:
  Rope() {
    len = w = sum = 0;
    data = "";
  }

  Rope(string data) : data(data) {
    sum = 0;
    for (const auto &ch : data) {
      sum += ch;
      sum %= MOD;
    }
    len = w = data.size();
  }

  Rope(shared_ptr<const Rope> left, shared_ptr<const Rope> right) {
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

  shared_ptr<const Rope> copy(int i, int j) const {
    return make_shared<const Rope>(data.substr(i, j - i + 1));
  }

  shared_ptr<const Rope> copy() const {
    return make_shared<const Rope>(data);
  }

  shared_ptr<const Rope> substr(int64_t i, int64_t j) const {
    if (i > j) return make_shared<const Rope>();

    if (i == 0 && j == this->len-1) {
      if (isLeaf())
        return copy();
      else
        return make_shared<const Rope>(left, right);
    }

    if (isLeaf()) {
      return copy(i, j);
    }

    shared_ptr<const Rope> l, r;

    if (i < w && left) {
      l = left->substr(i, min(w-1, j));      
    }

    if (w <= j && right) {
      r = right->substr(max(i - w, int64_t{0}), j - w);
    }

    return make_shared<const Rope>(l, r);
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

  vector<shared_ptr<const Rope>> roots;
  roots.push_back(make_shared<const Rope>(s));

  int64_t lo, hi;
  vector<tuple<int, int, int64_t, int64_t>> queries;

  const int N = 2510;
  int cnt[N];
  cnt[0] = 0;

  for (int i = 1, x, y; i < n; i++) {
    cnt[i] = 0;

    cin >> s;
    if (s == "SUB") {
      cin >> x >> lo >> hi;
      queries.emplace_back(x, -1, lo, hi);
      cnt[x]++;
    } else {
      cin >> x >> y;
      cnt[x]++;
      cnt[y]++;
      queries.emplace_back(x, y, 0, 0);
    }
  }

  for (int i = 1, x, y; i < n; i++) {
    tie(x, y, lo, hi) = queries[i-1];

    if (y == -1) {
      // SUB
      roots.push_back(roots[x]->substr(lo, hi-1));
      cnt[x]--;
    } else {
      // APP
      roots.push_back(make_shared<const Rope>(roots[x], roots[y]));
      cnt[x]--;
      cnt[y]--;
    }

    // free'd roots that we will not use anymore

    if (cnt[x] == 0)
      roots[x] = shared_ptr<const Rope>();

    if (y != -1 && cnt[y] == 0)
      roots[y] = shared_ptr<const Rope>();
  }

  cout << roots[n-1]->report() << "\n";

  return 0;
}

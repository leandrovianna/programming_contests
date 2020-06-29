// URI - Pulo do Sapo - 3107 
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class MinQueue {
  struct Elem {
    T min, value;
  };
  stack<Elem> st1, st2;

  void transfer() {
    while (!st1.empty()) {
      T value = st1.top().value;
      st1.pop();
      st2.push(Elem{
          st2.empty() ? value : min(value, st2.top().min),
          value});
    }
  }

  public:
  MinQueue() {}
  bool empty() {
    return st1.empty() && st2.empty();
  }

  T front() {
    if (empty())
      throw runtime_error("MinQueue is empty");

    if (st2.empty())
      transfer();

    return st2.top().value;
  }

  void push(T value) {
    T minimum = st1.empty() ? value : min(value, st1.top().min);
    st1.push(Elem{minimum, value});
  }

  void pop() {
    if (empty())
      throw runtime_error("MinQueue is empty");

    if (st2.empty())
      transfer();
    st2.pop();
  }

  T minimum() {
    if (empty())
      throw runtime_error("MinQueue is empty");

    if (st1.empty())
      return st2.top().min;
    else
      return min(st1.top().min, st2.top().min);
  }
};

const int N = 1000100;
int rock[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  rock[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> rock[i];
  }
  rock[n+1] = m;

  int x, y;
  cin >> x >> y;

  const int inf = 1e9;

  // f - number of jumps (last jump was short)
  // g - number of jumps (last jump was long)
  MinQueue<pair<int, int>> f1, f2, g;
  f1.push({0, 0});
  f2.push({0, 0});
  g.push({0, 0});

  int ans = -1;

  for (int i = 1, j, v; i <= n+1; i++) {
    while (!f1.empty()) {
      tie(v, j) = f1.front();
      if (rock[j] < rock[i] - x) f1.pop();
      else break;
    }
    while (!g.empty()) {
      tie(v, j) = g.front();
      if (rock[j] < rock[i] - x) g.pop();
      else break;
    }
    while (!f2.empty()) {
      tie(v, j) = f2.front();
      if (rock[j] < rock[i] - y) f2.pop();
      else break;
    }

    int vf = inf;
    if (!f1.empty())
      vf = 1 + min(f1.minimum().first, g.minimum().first);

    int vg = inf;
    if (!f2.empty())
      vg = 1 + f2.minimum().first;

    f1.push({vf, i});
    f2.push({vf, i});
    g.push({vg, i});

    if (i == n+1) {
      ans = min(vf, vg);
    }
  }

  cout << (ans >= inf ? -1 : ans) << "\n";
  
  return 0;
}

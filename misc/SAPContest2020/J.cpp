#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
pair<int, int> building[N];
pair<int, int> g[N];
int64_t npath[N];
const int64_t mod = 1e9 + 7;

int ft[N];

int query_max(int x) {
  x++;
  int s = -1;
  while (x > 0) {
    s = max(s, ft[x]);
    x -= (x & -x);
  }
  return s;
}

int query_min(int x) {
  x++;
  int s = N;
  while (x > 0) {
    s = min(s, ft[x]);
    x -= (x & -x);
  }
  return s == N ? -1 : s;
}

void update(int x, int v) {
  x++;
  while (x < N) {
    ft[x] = v;
    x += (x & -x);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> values;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> building[i].second >> building[i].first;
    values.push_back(-building[i].second);
  }

  sort(values.begin(), values.end());
  map<int, int> idx;
  for (const auto &x : values) {
    if (idx.find(-x) == idx.end())
      idx[-x] = idx.size();
  }

  for (int x = 0; x < int(idx.size()); x++)
    update(x, -1);

  sort(building, building+n);

  for (int i = 0; i < n; i++) {
    g[i].first = query_max(idx[building[i].second]);
    update(idx[building[i].second], i);
  }

  for (int x = 0; x < int(idx.size()); x++)
    update(x, N);
  
  for (int i = n-1; i >= 0; i--) {
    g[i].second = query_min(idx[building[i].second]);
    update(idx[building[i].second], i);
  }


  vector<pair<int, int>> process_queue;
  for (int i = 0; i < n; i++) {
    process_queue.push_back({-building[i].second, i});
  }
  sort(process_queue.begin(), process_queue.end());
  int64_t ans = 0;

  for (const auto &p : process_queue) {
    int i = p.second;

    npath[i] = 0;
    if (g[i] == make_pair(-1, -1))
      npath[i] = 1;

    if (g[i].first != -1)
      npath[i] = (npath[i] + npath[g[i].first]) % mod;

    if (g[i].second != -1)
      npath[i] = (npath[i] + npath[g[i].second]) % mod;

    ans = (ans + npath[i]) % mod;
  }

  cout << ans << "\n";

  return 0;
}

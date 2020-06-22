#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<pair<int, int64_t>> g[N];
int64_t ans[N];

void dfs(int v, int p, int64_t minw) {
  ans[v] = minw;

  int u;
  int64_t w;
  for (const auto &e : g[v]) {
    tie(u, w) = e;

    if (u == p) continue;

    dfs(u, v, min(minw, w));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  
  int64_t c;
  for (int i = 0, v, u; i < n-1; i++) {
    cin >> v >> u >> c;
    g[v].push_back({u, c});
    g[u].push_back({v, c});
  }

  dfs(n, 0, INT_MAX);
  
  for (int v = 1; v <= n-1; v++) {
    cout << ans[v];
    if (v == n-1)
      cout << "\n";
    else
      cout << " ";
  }
  return 0;
}

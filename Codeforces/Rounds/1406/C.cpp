// Codeforces - Link Cut Centroids - 1406C
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int sz[N], lcc[N], n;

int dfs(int v, int p) {
  sz[v] = 1;
  lcc[v] = 0;

  for (const auto &u : g[v]) {
    if (u != p) {
      int x = dfs(u, v);
      lcc[v] = max(lcc[v], x);
      sz[v] += x;
    }
  }

  lcc[v] = max(lcc[v], n - sz[v]);

  return sz[v];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    for (int v = 1; v <= n; v++) {
      g[v].clear();
    }

    for (int i = 0, x, y; i < n-1; i++) {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    dfs(1, 0);

    int minlcc = n+10, v1 = -1, v2 = -1;
    for (int v = 1; v <= n; v++) {
      if (lcc[v] < minlcc) {
        minlcc = lcc[v];
        v1 = v;
        v2 = -1;
      } else if (lcc[v] == minlcc) {
        v2 = v;
      }
    }

    if (v2 == -1) {
      cout << "1 " << g[1].front() << "\n";
      cout << "1 " << g[1].front() << "\n";
    } else {
      int w = -1, s = 0;
      for (const auto &u : g[v1]) {
        if (u != v2 && sz[u] > s) {
          s = sz[u];
          w = u;
        }
      }

      cout << v1 << " " << w << "\n";
      cout << v2 << " " << w << "\n";
    }
  }
  return 0;
}

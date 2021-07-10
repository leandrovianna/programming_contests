// Codeforces Gym - Help Conan - 101778D
#include <bits/stdc++.h>
using namespace std;

const int N = 20;

struct {
  int u, v, c;
} edges[N*N];

int important[N];

struct union_find {
  int parent[N], size[N];
  void init(int n) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (size[x] < size[y])
      swap(x, y);

    parent[y] = x;
    size[x] += size[y];
  }
};

union_find uf;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, m, k;
  cin >> t;

  while (t--) {
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
      cin >> edges[i].u >> edges[i].v >> edges[i].c;
      edges[i].u--;
      edges[i].v--;
    }

    sort(edges, edges+m, [](const auto &a, const auto &b) {
        return a.c < b.c;
      });

    for (int i = 0; i < k; i++) {
      cin >> important[i];
      important[i]--;
    }

    int ans = 1e9;

    for (int mask = 0; mask < (1 << n); mask++) {
      bool ok = true;
      for (int i = 0; i < k; i++) {
        ok = ok && ((1 << important[i]) & mask);
      }

      if (!ok) continue;

      int w = 0;
      uf.init(n);

      for (int i = 0; i < m; i++) {
        if ((mask & (1 << edges[i].u)) && (mask & (1 << edges[i].v))) {
          if (uf.find(edges[i].u) != uf.find(edges[i].v)) {
            //cout << edges[i].u << " <=> " << edges[i].v << endl;
            uf.join(edges[i].u, edges[i].v);
            w += edges[i].c;
          }
        }
      }

      set<int> ss;
      for (int i = 0; i < k; i++) {
        ss.insert(uf.find(important[i]));
      }

      if (ss.size() == 1) {
        ans = min(ans, w);
      }
    }

    cout << ans << "\n";
  }
  return 0;
}

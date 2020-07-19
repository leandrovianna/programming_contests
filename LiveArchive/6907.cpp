// LiveArchive - Body Building - 6907
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
vector<int> g[N];
bool vis[N], vis2[N];

/// Bridges
int low[N], tin[N];
int timer;
vector<pair<int, int>> bridges;
void dfs(int v, int p = -1) {
  vis[v] = true;
  tin[v] = low[v] = timer++;
  for (const auto &to : g[v]) {
    if (to == p) continue;
    if (vis[to]) {
      low[v] = min(low[v], tin[to]);
    } else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if (low[to] > tin[v])
        bridges.emplace_back(v, to);
    }
  }
}

void find_bridges(int n) {
  timer = 0;
  bridges.clear();
  memset(vis, false, sizeof(vis));
  memset(tin, -1, sizeof(tin));
  memset(low, -1, sizeof(low));
  for (int v = 0; v < n; v++) {
    if (!vis[v]) dfs(v);
  }
}
/// End Bridges

void dfs2(int v) {
  if (vis2[v]) return;
  vis2[v] = true;

  for (const auto &u : g[v]) {
    if (!vis2[u]) {
      dfs2(u);
    }
  }
}

pair<int, bool> is_complete(int n) {
  int countV = 0, countE = 0;
  for (int v = 0; v < n; v++) {
    if (vis2[v]) {
      countV++;
      countE += g[v].size();
    }
  }
  countE--;

  return {countV, countE == (countV-1)*countV};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, m;
  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    cin >> n >> m;

    for (int v = 0; v < n; v++) {
      g[v].clear();
    }

    for (int i = 0, a, b; i < m; i++) {
      cin >> a >> b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    find_bridges(n);
    int ans = 0, a, b;
    for (const auto &bridge : bridges) {
      tie(a, b) = bridge;

      // from a
      memset(vis2, false, sizeof(vis2));
      vis2[b] = true;
      dfs2(a);

      vis2[b] = false;
      auto p = is_complete(n);

      // from b
      memset(vis2, false, sizeof(vis2));
      vis2[a] = true;
      dfs2(b);

      vis2[a] = false;
      auto q = is_complete(n);

      if (p.second && q.second && p.first == q.first)
        ans++;
    }

    cout << "Case #" << ti << ": " << ans << "\n";
  }
  
  return 0;
}

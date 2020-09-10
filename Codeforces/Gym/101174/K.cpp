// Codeforces Gym - Balls and Needles - 101174K
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> point3;
typedef pair<int, int> point2;

const int K = 50100;
const int N = 2*K;
vector<int> g[N], h[N];
bool vis[N];

bool dfs(int v, int p) {
  vis[v] = true;

  for (const auto &u : g[v]) {
    if (u == v || u == p) continue;

    if (!vis[u]) {
      if (dfs(u, v))
        return true;
    } else {
      return true;
    }
  }

  return false;
}

bool dfs2(int v, int p) {
  vis[v] = true;

  for (const auto &u : h[v]) {
    if (u == v || u == p) continue;

    if (!vis[u]) {
      if (dfs2(u, v))
        return true;
    } else {
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k;
  cin >> k;

  map<point2, int> idx2;
  map<point3, int> idx3;

  int x1, y1, z1, x2, y2, z2;
  for (int i = 0; i < k; i++) {
    cin >> x1 >> y1 >> z1
      >> x2 >> y2 >> z2;

    auto p1 = point3{x1, y1, z1};
    auto p2 = point3{x2, y2, z2};

    if (idx3.find(p1) == idx3.end())
      idx3[p1] = idx3.size();
    if (idx3.find(p2) == idx3.end())
      idx3[p2] = idx3.size();

    int a = idx3[p1], b = idx3[p2];
    if (a != b) {
      g[a].push_back(b);
      g[b].push_back(a);
    }

    auto q1 = point2{x1, y1};
    auto q2 = point2{x2, y2};

    if (idx2.find(q1) == idx2.end())
      idx2[q1] = idx2.size();
    if (idx2.find(q2) == idx2.end())
      idx2[q2] = idx2.size();

    a = idx2[q1];
    b = idx2[q2];
    if (a != b) {
      h[a].push_back(b);
      h[b].push_back(a);
    }
  }

  int n = idx3.size(), m = idx2.size();

  for (int v = 0; v < n; v++) {
    sort(g[v].begin(), g[v].end());
    auto it = unique(g[v].begin(), g[v].end());
    g[v].erase(it, g[v].end());
  }
  for (int v = 0; v < m; v++) {
    sort(h[v].begin(), h[v].end());
    auto it = unique(h[v].begin(), h[v].end());
    h[v].erase(it, h[v].end());
  }

  bool trueClosed = false;
  fill(vis, vis+n, false);
  for (int v = 0; v < n; v++) {
    if (!vis[v]) {
      trueClosed = trueClosed || dfs(v, -1);
    }
  }

  bool floorClosed = false;
  fill(vis, vis+m, false);
  for (int v = 0; v < m; v++) {
    if (!vis[v]) {
      floorClosed = floorClosed || dfs2(v, -1);
    }
  }

  if (trueClosed)
    cout << "True closed chains\n";
  else
    cout << "No true closed chains\n";

  if (floorClosed)
    cout << "Floor closed chains\n";
  else
    cout << "No floor closed chains\n";

  return 0;
}

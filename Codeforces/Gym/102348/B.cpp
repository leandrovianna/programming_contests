// Codeforces - Interesting Vertices - 102348B
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
bool color[N];
vector<int> g[N];
int subtree[N];

int dfs_pre(int v, int p) {
  subtree[v] = color[v] ? 1 : 0;

  for (const auto &u : g[v]) {
    if (u == p) continue;

    subtree[v] += dfs_pre(u, v);
  }

  return subtree[v];
}

void dfs(int v, int p, int k, vector<int> &selected) {
  subtree[p] -= subtree[v];
  subtree[v] = k;

  bool interesting = true;
  for (const auto &u : g[v]) {
    interesting = interesting && subtree[u] > 0;

    if (u == p) continue;
    dfs(u, v, k, selected);
  }

  if (interesting && !color[v])
    selected.push_back(v);

  subtree[v] -= subtree[p];
  subtree[p] = k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  
  for (int i = 0, a; i < k; i++) {
    cin >> a;
    a--;
    color[a] = true;
  }

  for (int i = 0, u, v; i < n-1; i++) {
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  const int dummy = N-1;

  dfs_pre(0, dummy);

  subtree[dummy] = k;
  vector<int> selected;
  dfs(0, dummy, k, selected);

  sort(selected.begin(), selected.end());
  cout << selected.size() << "\n";
  for (const auto &v : selected) {
    cout << v+1 << " ";
  }
  cout << "\n";

  return 0;
}

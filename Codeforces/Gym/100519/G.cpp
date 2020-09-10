// Codeforces Gym - Genealogy - 100519G
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
vector<int> g[N], gr[N];
bool used[N];
vector<int> order, component;

void dfs1(int v) {
  used[v] = true;
  for (const auto &u : g[v]) {
    if (!used[u])
      dfs1(u);
  }
  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);
  for (const auto &u : gr[v]) {
    if (!used[u]) {
      dfs2(u);
    }
  }
}

int depth[N];

void kosaraju(int n) {
  fill(used, used+n, false);
  for (int v = 0; v < n; v++) {
    if (!used[v])
      dfs1(v);
  }

  fill(used, used+n, false);
  component.clear();

  for (int i = 0; i < n; i++) {
    int v = order[n-1-i];
    if (!used[v]) {
      dfs2(v);
      if (component.size() >= 2) {
        for (const auto &u : component) {
          depth[u] = component.size();
        }
      }
      component.clear();
    }
  }
}

int compute(int v) {
  if (depth[v] != -1) return depth[v];

  int d = 1;
  for (const auto &u : g[v]) {
    d = max(d, 1 + compute(u));
  }

  return depth[v] = d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<tuple<string, string, string>> names;
  map<string, int> idx;

  int n;
  cin >> n;
  string family, first, father;
  for (int i = 0; i < n; i++) {
    cin >> family >> first;
    cin.ignore(8);
    cin >> father;

    names.push_back({family, first, father});
    // assert(idx.find(family+first) == idx.end());
    idx[family+first] = i;
  }

  for (int i = 0; i < n; i++) {
    tie(family, first, father) = names[i];

    if (idx.find(family+father) != idx.end()) {
      int a = idx[family+first], b = idx[family+father];
      if (a != b) {
        g[a].push_back(b);
        gr[b].push_back(a);
      }
    }
  }

  fill(depth, depth+n, -1);
  kosaraju(n);

  for (int v = 0; v < n; v++) {
    if (depth[v] == -1) {
      compute(v);
    }
  }

  int ans = 0;
  for (int v = 0; v < n; v++) {
    ans = max(ans, depth[v]);
  }
  cout << ans << "\n";

  return 0;
}

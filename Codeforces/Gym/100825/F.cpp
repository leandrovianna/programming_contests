// Codeforces Gym - Transportation Delegation - 100825F
#include <bits/stdc++.h>
using namespace std;

struct FlowEdge {
  int v, u;
  int64_t cap, flow = 0;
  FlowEdge() {}
  FlowEdge(int v, int u, int64_t cap)
    : v(v), u(u), cap(cap) {}
};

struct Dinic {
  static const int N = 3000;
  const int64_t flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<int> adj[N];
  int n, m = 0;
  int s, t;
  int level[N], ptr[N];
  queue<int> q;

  Dinic() {}

  void init(int n, int s, int t) {
    this->n = n;
    this->s = s;
    this->t = t;
    m = 0;
    edges.clear();
  }

  void add_edge(int v, int u, int64_t cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m+1);
    m += 2;
  }

  bool bfs() {
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (const int &id : adj[v]) {
        if (edges[id].cap - edges[id].flow < 1)
          continue;
        if (level[edges[id].u] != -1)
          continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }

  int64_t dfs(int v, int64_t pushed) {
    if (pushed == 0)
      return 0;
    if (v == t)
      return pushed;
    for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;

      int64_t tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
        continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  int64_t flow() {
    int64_t f = 0;
    while (true) {
      fill(level, level+n, -1);
      level[s] = 0;
      q.push(s);
      if (!bfs())
        break;
      fill(ptr, ptr+n, 0);
      while (int64_t pushed = dfs(s, flow_inf)) {
        f += pushed;
      }
    }
    return f;
  }
};

Dinic dinic;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int s, r, f, t;
  cin >> s >> r >> f >> t;

  const int source = 0, sink = 1;
  auto getState = [](int i) {
    return 2 + i;
  };
  auto getTransp = [s](int i) {
    // return in, +1 to get out
    return 2 + s + 2 * i;
  };

  int n = 2 + s + 2 * t;
  dinic.init(n, source, sink);

  map<string, int> idx;
  string name;
  for (int i = 0, v; i < r; i++) {
    cin >> name;
    v = idx.size();
    idx[name] = v;

    dinic.add_edge(source, getState(v), 1);
  }

  for (int i = 0, v; i < f; i++) {
    cin >> name;
    v = idx.size();
    idx[name] = v;

    dinic.add_edge(getState(v), sink, 1);
  }

  for (int i = 0, n, v, tin, tout; i < t; i++) {
    tin = getTransp(i);
    tout = tin+1;
    dinic.add_edge(tin, tout, 1);

    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> name;
      if (idx.find(name) == idx.end())
        idx[name] = idx.size();
      v = idx[name];

      dinic.add_edge(getState(v), tin, dinic.flow_inf);
      dinic.add_edge(tout, getState(v), dinic.flow_inf);
    }
  }

  int64_t ans = dinic.flow();
  cout << ans << "\n";

  return 0;
}

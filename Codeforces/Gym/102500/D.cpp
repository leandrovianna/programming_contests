// Codeforces Gym - Disposable Switches - 102500D
#include <bits/stdc++.h>
using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, less<T>>;

const int N = 2100;
vector<pair<int, int64_t>> g[N];
const int64_t inf = 1e18;
int64_t dist[N];

void dijkstra(int s, int64_t c) {
  min_heap<pair<int64_t, int>> heap;
  heap.push({0, s});
  dist[s] = 0;

  int v, u;
  int64_t w;

  while (!heap.empty()) {
    auto p = heap.top();
    heap.pop();
    v = p.second;

    for (const auto &edge : g[v]) {
      tie(u, w) = edge;

      if (dist[u] > dist[v] + w + c) {
        dist[u] = dist[v] + w + c;
        heap.push({dist[u], u});
      }
    }
  }
}

bool mark[N], vis[N];
void bfs(int s, int t, int64_t c) {
  queue<int> q;
  q.push(t);

  int v, u;
  int64_t w;

  while (!q.empty()) {
    v = q.front();
    q.pop();

    mark[v] = true;
    if (vis[v])
      continue;
    vis[v] = true;

    if (v == s)
      continue;

    for (const auto &edge : g[v]) {
      tie(u, w) = edge;

      if (dist[v] == dist[u] + w + c)
        q.push(u);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0, a, b, l; i < m; i++) {
    cin >> a >> b >> l;
    a--;
    b--;
    g[a].push_back({b, l});
    g[b].push_back({a, l});
  }

  fill(dist, dist+n, inf);
  dijkstra(0, 0);
  fill(vis, vis+n, false);
  bfs(0, n-1, 0);

  for (int64_t c = 1; c < (1LL << 60); c *= 2) {
    fill(dist, dist+n, inf);
    dijkstra(0, c);
    fill(vis, vis+n, false);
    bfs(0, n-1, c);
  }

  set<int> answer;
  for (int v = 0; v < n; v++) {
    if (!mark[v])
      answer.insert(v+1);
  }

  cout << answer.size() << "\n";
  for (const auto &v : answer) {
    cout << v << " ";
  }
  cout << "\n";
  return 0;
}

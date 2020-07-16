// UVa - Bank Robbery - 13127 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
vector<pair<int, int64_t>> g[N];
int64_t dist[N];
bool is_bank[N], is_police[N];

const int64_t inf = 1e18;
template<typename T>
using min_heap = priority_queue<T, vector<T>, less<T>>;

void dijkstra(int n) {
  min_heap<pair<int64_t, int>> q;

  for (int v = 0; v < n; v++) {
    if (is_police[v]) {
      q.push({0, v});
      dist[v] = 0;
    } else {
      dist[v] = inf;
    }
  }

  int v, u;
  int64_t w;
  while (!q.empty()) {
    auto p = q.top();
    q.pop();

    v = p.second;

    for (const auto &edge : g[v]) {
      tie(u, w) = edge;
      if (dist[u] > dist[v] + w) {
        dist[u] = dist[v] + w;
        q.push({dist[u], u});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, b, p;

  while (cin >> n >> m >> b >> p) {
    for (int v = 0; v < n; v++) {
      g[v].clear();
      is_bank[v] = false;
      is_police[v] = false;
    }

    for (int i = 0, u, v, w; i < m; i++) {
      cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }

    for (int i = 0, x; i < b; i++) {
      cin >> x;
      is_bank[x] = true;
    }

    for (int i = 0, x; i < p; i++) {
      cin >> x;
      is_police[x] = true;
    }

    dijkstra(n);

    int64_t max_dist = 0;
    vector<int> banks;
    for (int v = 0; v < n; v++) {
      if (is_bank[v]) {
        if (dist[v] > max_dist) {
          banks.clear();
          banks.push_back(v);
          max_dist = dist[v];
        } else if (dist[v] == max_dist) {
          banks.push_back(v);
        }
      }
    }

    cout << banks.size();
    if (max_dist == inf)
      cout << " *\n";
    else
      cout << " " << max_dist << "\n";
    for (int i = 0, sz = banks.size(); i < sz; i++) {
      cout << banks[i];
      cout << (i < sz-1 ? " " : "\n");
    }
  }

  return 0;
}

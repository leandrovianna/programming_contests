// UVa - Interstellar Travel - 12948
#include <bits/stdc++.h>
using namespace std;

const int64_t inf = 1e18;
const int N = 310, Z = 300+1;

struct Edge {
  Edge(int to, int64_t cost, int64_t time)
    : to(to), cost(cost), time(time) {}
  int to;
  int64_t cost = 0, time = 0;
};
vector<Edge> edges;
vector<int> g[N];
bool inqueue[N][N];

pair<int64_t, int64_t> dist[N][N];

void spfa(const int s, const int n) {
  for (int v = 0; v < n; v++) {
    for (int i = 0; i <= Z; i++) {
      dist[v][i] = {inf, inf};
      inqueue[v][i] = false;
    }
  } 


  dist[s][0] = {0, 0};
  queue<pair<int, int>> q;
  q.push({s, 0});
  inqueue[s][0] = true;

  int v, step;
  while (!q.empty()) {
    tie(v, step) = q.front();
    q.pop();
    inqueue[v][step] = false;

    for (const auto &idx : g[v]) {
      auto edge = edges[idx];
      int u = edge.to;

      auto newDist = dist[v][step];
      newDist.first += edge.cost;
      newDist.second += edge.time;

      if (newDist < dist[u][step+1]) {
        dist[u][step+1] = newDist;
        if (!inqueue[u][step+1]) {
          q.push({u, step+1});
          inqueue[u][step+1] = true;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int p, f, q;
  int64_t t, c;
  string s;

  for (int ti = 0; cin >> p >> f >> q; ti++) {
    if (ti > 0) {
      cout << ".\n";
    }

    map<string, int> idx;
    edges.clear();
    for (int i = 0; i < p; i++) {
      g[i].clear();
    }

    for (int i = 0; i < p; i++) {
      cin >> s;
      idx[s] = i;
    }

    for (int i = 0, a, b; i < f; i++) {
      cin >> s;
      a = idx[s];
      cin >> s;
      b = idx[s];
      cin >> c >> t;

      g[a].push_back(edges.size());
      edges.push_back({b, c, t});
    }

    cin >> s;
    int source = idx[s];

    spfa(source, p);

    for (int i = 0, n; i < q; i++) {
      cin >> s >> n;
      int dest = idx[s];

      auto ans = make_pair(inf, inf);
      for (int stops = 0; stops <= n+1; stops++) {
        ans = min(ans, dist[dest][stops]);
      }

      if (ans == make_pair(inf, inf))
        cout << "* *\n";
      else
        cout << ans.first << " " << ans.second << "\n";
    }
  }
  
  return 0;
}

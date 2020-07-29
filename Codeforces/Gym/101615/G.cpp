// Codeforces - Security Badge - 101615G
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Interval;

const int N = 1010;
vector<pair<int, Interval>> g[N];
bool vis[N];

bool bfs(int s, int x, int t) {
  queue<int> q;
  q.push(s);
  fill(vis, vis+N, false);
  vis[s] = true;

  while (!q.empty()) {
    auto v = q.front();
    q.pop();

    if (v == t) return true;

    Interval interval;
    int u;
    for (const auto &edge : g[v]) {
      tie(u, interval) = edge;

      if (!vis[u] && interval.first <= x && x <= interval.second) {
        q.push(u);
        vis[u] = true;
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  int s, t;
  cin >> s >> t;

  vector<int> values;
  for (int i = 0, a, b, c, d; i < m; i++) {
    cin >> a >> b >> c >> d;
    g[a].push_back({b, {c, d}});
    values.push_back(c);
    values.push_back(d+1);
  }
  values.push_back(k+1);

  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());

  int answer = 0;
  for (int i = 0, k = values.size(); i < k-1; i++) {
    if (bfs(s, values[i], t)) {
      answer += values[i+1] - values[i];
    }
  }

  cout << answer << "\n";
  
  return 0;
}

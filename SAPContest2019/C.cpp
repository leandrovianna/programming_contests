#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
vector<pair<int, int64_t>> g[N];
int64_t dist[N];
bool vis[N];
const int64_t inf = 1e18;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void djikstra(int s) {
    min_heap<pair<int64_t, int>> q;

    q.push({0, s});
    dist[s] = 0;

    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        int v = p.second;
        if (vis[v]) continue;
        vis[v] = true;

        for (const auto &ed : g[v]) {
            int u = ed.first;

            if (dist[u] > dist[v] + ed.second) {
                dist[u] = dist[v] + ed.second;
                q.push({dist[u], u});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f;
    int c, t;

    cin >> f;

    int64_t ans = 0, d;

    while (f--) {
        cin >> c >> t; 

        for (int v = 0; v < N; v++) {
            g[v].clear();
            dist[v] = inf;
            vis[v] = false;
        }
        for (int i = 0, a, b; i < t; i++) {
            cin >> a >> b >> d;
            g[a].push_back({b, d});
            // g[b].push_back({a, d});
        }

        djikstra(1);
        ans += dist[c];
    }

    cout << ans << "\n";
    return 0;
}

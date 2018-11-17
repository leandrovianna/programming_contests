// TAP 2018/2 - H8 - Highway Decommission
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u;
    int64_t l, c;
};

const int64_t INF = 1e18;
const int N = 10010;
vector<edge> g[N];
bool vis[N];
int parent[N];
int64_t dist[N];
int64_t cost[N];

void dijkstra(int s, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        vis[i] = false;
        parent[i] = -1;
    }

    using pii = pair<int64_t, int>;
    set<pii> queue;
    dist[s] = 0;
    queue.insert({0, s});

    while (!queue.empty()) {
        auto p = *queue.begin();
        int v = p.second;
        queue.erase(queue.begin());

        if (vis[v])
            continue;
        vis[v] = true;

        for (const auto &e : g[v]) {
            // difference for normal dijkstra: cost[e.u] > e.c
            if (dist[e.u] > dist[v] + e.l
                    || (dist[e.u] == dist[v] + e.l && cost[e.u] > e.c)) {
                dist[e.u] = dist[v] + e.l;
                parent[e.u] = v;
                cost[e.u] = e.c;
                queue.insert({dist[e.u], e.u});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;

    for (int i = 0, a, b, l, c; i < m; i++) {
        cin >> a >> b >> l >> c;
        g[a].push_back({b, l, c});
        g[b].push_back({a, l, c});
    }

    dijkstra(1, n);

    int64_t ans = 0;

    for (int u = 2; u <= n; u++) {
        ans += cost[u];
    }

    cout << ans << endl;
    return 0;
}

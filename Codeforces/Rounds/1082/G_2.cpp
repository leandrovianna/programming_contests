// Codeforces - Petya and Graph - 1082G Edu Round
#include <bits/stdc++.h>
using namespace std;

struct Edmonds {
    static const int64_t inf = 1e18;
    static const int V = 2010;
    int64_t adj[V][V];
    vector<int> g[V];
    int p[V]; // parent vector
    int64_t dist[V];
    int n, s, t;

    Edmonds(int n, int s, int t) : n(n), s(s), t(t) {
    }

    int64_t augmented() {
        int u = t;
        int64_t minimum = inf;

        // find minimum flow in augmented path
        while (p[u] != -1) {
            minimum = min(adj[p[u]][u], minimum);
            u = p[u];
        }

        // walk in augment path updating flow
        u = t;
        while (p[u] != -1) {
            adj[p[u]][u] -= minimum;
            adj[u][p[u]] += minimum;
            u = p[u];
        }

        return minimum; // return minimum flow in augmented path
    }

    int64_t flow() {
        int64_t mf = 0, // max flow answer
                f = 1;
        int u;

        while (f > 0) {
            f = 0;
            for (int i = 0; i < n; i++)
                dist[i] = inf, p[i] = -1;
            dist[s] = 0;

            queue<int> q;
            q.push(s);

            while (!q.empty()) {
                u = q.front();
                q.pop();

                // stop if reach sink t
                if (u == t) break;

                for (const auto &v : g[u]) {
                    if (adj[u][v] > 0 && dist[v] == inf) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        p[v] = u;
                    }
                }
            }

            // verify if bfs stop when reach sink t
            if (u == t) {
                // find minimum flow in augmented path
                f = augmented();

                // update max flow of network
                mf += f;
            }
        }

        return mf;
    }

    void add_edge(int v, int u, int64_t cap) {
        adj[v][u] = cap;
        adj[u][v] = 0;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    void add_bi_edge(int v, int u, int64_t cap) {
        adj[v][u] = cap;
        adj[u][v] = cap;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    void inc_edge(int v, int u, int64_t cap) {
        adj[v][u] += cap;
    }
};

Edmonds edmonds(2002, 2000, 2001);
int main() {
    int n, m;

    cin >> n >> m;

    int s = 2000;
    int t = 2001;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        edmonds.add_edge(i, t, x);
    }

    int64_t sum_edges = 0;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        sum_edges += w;
        edmonds.add_edge(n+i, u-1, LLONG_MAX);
        edmonds.add_edge(n+i, v-1, LLONG_MAX);
        edmonds.add_edge(s, n+i, w);
    }

    int64_t max_flow = edmonds.flow();

    cout << sum_edges - max_flow << "\n";

    return 0;
}

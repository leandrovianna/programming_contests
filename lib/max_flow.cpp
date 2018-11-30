// Lib - Edmonds-Karp Algorithm
// UVA - 820 - Network Bandwidth
#include <bits/stdc++.h>
using namespace std;

struct Edmonds {
    static const int64_t inf = 1e18;
    static const int V = 150;
    int64_t adj[V][V];
    vector<int> g[V];
    int p[V]; // parent vector
    int64_t dist[V];
    int n, s, t;

    Edmonds(int n, int s, int t) : n(n), s(s), t(t) {
        clear();
    }

    void clear() {
        for (int i = 0; i < n; i++)
            g[i].clear();
        memset(adj, 0, sizeof(adj));
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
        if (adj[v][u] == 0)
            g[v].push_back(u);
        adj[v][u] += cap;
    }
};

int main() {
	ios::sync_with_stdio(false);
		
	int n, m, k;
	int a, b, source, sink;
	int64_t c;

	k = 1;
	while (cin >> n, n) {
		cin >> source >> sink >> m;
		source--;
		sink--;

		Edmonds edmonds(n, source, sink);

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			a--;
			b--;
			edmonds.inc_edge(a, b, c);
			edmonds.inc_edge(b, a, c);
		}

		c = edmonds.flow();
		cout << "Network " << k << "\nThe bandwidth is " << c << ".\n\n";
		k++;
	}

	return 0;
}

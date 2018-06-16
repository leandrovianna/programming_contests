// URI Online Judge - Caminhão - 1476
// Solution: LCA to calculate the minimum edge cost
#include <bits/stdc++.h>
using namespace std;


const int N = 100 * 1000 + 10;
const int L = 20; // log2(N)

struct Union_find {
    int parent[N];
    int sz[N];

    Union_find() {}

    void init(int size) {
        assert(size < N);
        for (int i = 0; i <= size; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        // x should be smaller tree
        if (sz[x] > sz[y]) swap(x, y);

        parent[x] = y;
        sz[y] += sz[x];
    }
};

struct edge {
    int x, y;
    int64_t w;
    edge() : x(0), y(0), w(0) {}
    edge(int x, int y, int64_t w) : x(x), y(y), w(w) {}
    bool operator< (const edge &other) {
        return this->w > other.w
            || (this->w == other.w && this->x < other.x)
            || (this->w == other.w && this->x == other.x && this->y == other.y);
    }
};

struct Kruskal {
    Union_find uf;
    vector<edge> &edges;

    Kruskal(vector<edge> &edges) : edges(edges) {}

    void mst(vector<pair<int, int64_t> > g[], const int maxv) {
        // maxv - max of vertex id
        uf.init(maxv+1);
        sort(edges.begin(), edges.end());

        for (const auto &ed : edges) {
            if (uf.find(ed.x) != uf.find(ed.y)) {
                uf.join(ed.x, ed.y);
                g[ed.x].push_back({ed.y, ed.w});
                g[ed.y].push_back({ed.x, ed.w});
            }
        }
    }
};

struct LCA {
    int parent[N][L];
    int lvl[N];
    int64_t minimum[N][L];
    int64_t maximum[N][L];

    LCA() {}

    void init(vector<pair<int, int64_t> > g[], int maxv, int root) {
        // maxv - max of vertex id

        function<void(int, int)> dfs = [&](int v, int p) {
            parent[v][0] = p;
            lvl[v] = lvl[p] + 1;

            for (const auto &ed : g[v]) {
                int u = ed.first;

                if (u == p) continue;

                minimum[u][0] = ed.second;
                maximum[u][0] = ed.second;
                dfs(u, v);
            }
        };

        lvl[root] = 0;
        parent[root][0] = root;
        minimum[root][0] = INT_MAX;
        maximum[root][0] = 0;

        dfs(root, root);

        for (int e = 1; e < L; e++) {
            for (int v = 1; v <= maxv; v++) {
                parent[v][e] = parent[parent[v][e-1]][e-1];
                minimum[v][e] = min(minimum[v][e-1],
                        minimum[parent[v][e-1]][e-1]);
                maximum[v][e] = max(maximum[v][e-1],
                        maximum[parent[v][e-1]][e-1]);
            }
        }
    }

    int64_t min_edge(int a, int b) {
        if (lvl[a] < lvl[b]) swap(a, b);

        int d = lvl[a] - lvl[b];
        int64_t ans = INT_MAX;

        for (int e = 0; e < L; e++) {
            if (d & (1 << e)) {
                ans = min(ans, minimum[a][e]);
                a = parent[a][e];
            }
        }

        if (a != b) {
            for (int e = L-1; e >= 0; e--) {
                if (parent[a][e] != parent[b][e]) {
                    ans = min(ans, min(minimum[a][e], minimum[b][e]));
                    a = parent[a][e];
                    b = parent[b][e];
                }
            }

            ans = min(ans, min(minimum[a][0], minimum[b][0]));
        }

        return ans;
    }

    int64_t max_edge(int a, int b) {
        if (lvl[a] < lvl[b]) swap(a, b);

        int d = lvl[a] - lvl[b];
        int64_t ans = 0;

        for (int e = 0; e < L; e++) {
            if (d & (1 << e)) {
                ans = max(ans, maximum[a][e]);
                a = parent[a][e];
            }
        }

        if (a != b) {
            for (int e = L-1; e >= 0; e--) {
                if (parent[a][e] != parent[b][e]) {
                    ans = max(ans, max(maximum[a][e], maximum[b][e]));
                    a = parent[a][e];
                    b = parent[b][e];
                }
            }

            ans = max(ans, max(maximum[a][0], maximum[b][0]));
        }

        return ans;
    }
};

LCA lca;

int main() {
    int n, m, s;

    while (cin >> n >> m >> s) {
        vector<edge> edges;
        vector<pair<int, int64_t> > g[N];

        for (int i = 0, x, y; i < m; i++) {
            int64_t w;
            cin >> x >> y >> w;
            edges.push_back(edge(x, y, w));
        }

        Kruskal krus(edges);
        krus.mst(g, n);

        lca.init(g, n, 1);

        for (int i = 0, a, b; i < s; i++) {
            cin >> a >> b;
            cout << lca.min_edge(a, b) << "\n";
        }
    }
    return 0;
}

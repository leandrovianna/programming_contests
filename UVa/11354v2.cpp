// UVA - Bond - 11354 - LCA solution
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x, y;
    int64_t w;
    bool operator< (const edge &other) {
        return this->w < other.w
            || (this->w == other.w && this->x < other.x)
            || (this->w == other.w && this->x == other.x && this->y < other.y);
    }
};

const int N = 100 * 1000 + 10;
const int L = 20;

struct union_find {
    int parent[N];
    int sz[N];

    union_find() {
    }

    void init(int size) {
        assert(size < N);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    void join(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return;

        if (sz[x] < sz[y]) {
            parent[x] = y;
            sz[y] += sz[x];
        } else {
            parent[y] = x;
            sz[x] += sz[y];
        }
    }
};

edge edges[N];
vector<pair<int, int64_t> > g[N];

int parent[N][L];
int64_t maximum[N][L];
int lvl[N];

union_find uf;

void dfs(int v, int p) {
    lvl[v] = lvl[p] + 1;
    parent[v][0] = p;

    for (const auto &ed : g[v]) {
        int u = ed.first;
        if (u == p) continue;

        maximum[u][0] = ed.second;
        dfs(u, v);
    }
}

void pre_lca(int root, int size) {
    memset(lvl, 0, sizeof(lvl));
    memset(parent, 0, sizeof(parent));
    memset(maximum, 0, sizeof(maximum));

    lvl[0] = 0;
    parent[root][0] = 0;
    maximum[root][0] = 0;

    dfs(root, 0);

    for (int e = 1; e < L; e++) {
        for (int v = 1; v <= size; v++) {
            parent[v][e] = parent[parent[v][e-1]][e-1];
            maximum[v][e] = max(maximum[v][e-1], 
                    maximum[parent[v][e-1]][e-1]);
        }
    }
}

int64_t max_edge(int a, int b) {
    if (lvl[a] < lvl[b])
        swap(a, b);

    int diff = lvl[a] - lvl[b];

    int64_t ans = 0;

    for (int i = L-1; i >= 0; i--) {
        if (diff & (1 << i)) {
            ans = max(ans, maximum[a][i]);
            a = parent[a][i];
        }
    }

    if (a == b) return ans;

    for (int i = L-1; i >= 0; i--) {
        if ((1 << i) <= lvl[a] && parent[a][i] != parent[b][i]) {
            ans = max(ans, max(maximum[a][i], maximum[b][i]));
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    ans = max(ans, max(maximum[a][0], maximum[b][0]));

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    
    bool first = false;
    while (cin >> n >> m) {
        if (first) cout << "\n";
        first = true;

        uf.init(n+1);

        for (int i = 0; i < m; i++) {
            cin >> edges[i].x >>  edges[i].y >> edges[i].w;
        }

        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }

        sort(edges, edges+m);

        for (int i = 0, a, b; i < m; i++) {
            a = edges[i].x;
            b = edges[i].y;

            if (uf.find(a) != uf.find(b)) {
                uf.join(a, b); 
                g[a].push_back({b, edges[i].w});
                g[b].push_back({a, edges[i].w});
            }
        }

        pre_lca(1, n);

        cin >> q;
        for (int i = 0, a, b; i < q; i++) {
            cin >> a >> b;
            cout << max_edge(a, b) << "\n";
        }
    }

    return 0;
}


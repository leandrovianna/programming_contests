// URI - Caminhao - 1476
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;

struct edge {
    int a, b;
    int64_t w;
    bool operator< (const edge &other) {
        return this->w > other.w
            || (this->w == other.w && this->a < other.a);
    }
} edges[N];

struct query {
    int a, b, ans = -1;
} queries[N];

vector<int> queries_id[N];

struct union_find {
    int parent[N];
    int sz[N];

    union_find(int size) {
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

    pair<int, int> join(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return {x, y};

        if (sz[x] < sz[y]) {
            parent[x] = y;
            sz[y] += sz[x];
            return {y, x};
        } else {
            parent[y] = x;
            sz[x] += sz[y];
            return {x, y};
        }
    }
};

int main() {
    int n, m, s;

    while (cin >> n >> m >> s) {
        for (int i = 0; i < m; i++) {
            cin >> edges[i].a >> edges[i].b >> edges[i].w;
        }

        for (int i = 1; i <= n; i++) {
            queries_id[i].clear();
        }

        for (int i = 0, a, b; i < s; i++) {
            cin >> a >> b;
            queries[i].a = a;
            queries[i].b = b;
            queries[i].ans = -1;

            queries_id[a].push_back(i);
            queries_id[b].push_back(i);
        }

        // generate MST with Kruskal

        sort(edges, edges+m);

        union_find uf(n+1);

        for (int i = 0, a, b; i < m; i++) {
            a = edges[i].a;
            b = edges[i].b;

            if (uf.find(a) != uf.find(b)) {
                tie(a, b) = uf.join(a, b);

                for (const auto &id : queries_id[b]) {
                    if (queries[id].ans == -1 &&
                            uf.find(queries[id].a) == uf.find(queries[id].b)) {
                        queries[id].ans = edges[i].w;
                    } else {
                        queries_id[a].push_back(id);
                    }
                }

                queries_id[b].clear();
            }
        }

        for (int i = 0; i < s; i++) {
            cout << queries[i].ans << "\n";
        }
    }
    return 0;
}

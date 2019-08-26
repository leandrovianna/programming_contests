// Codeforces - 0-1-Tree - 1156D Edu Round 64
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
vector<pair<int, int>> g[N];
int parent[N];
int64_t comp[2][N], compsz[2][N];
int64_t sz[2][N];

void pre(int v, int p) {
    parent[v] = p;

    sz[0][v] = 1;
    sz[1][v] = 1;

    for (const auto &edge : g[v]) {
        int u = edge.first;

        if (u == p) continue;

        pre(u, v);
        sz[edge.second][v] += sz[edge.second][u];
    }
}

int64_t dfs(int v, int q, int type) {
    int64_t x = 1;
    comp[type][v] = q;

    for (const auto &edge : g[v]) {
        int u = edge.first;

        if (edge.second == type && !comp[type][u]) {
            x += dfs(u, q, type);
        }
    }

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1, x, y, c; i < n; i++) {
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }

    srand(time(nullptr));
    int root = 1 + rand() % n;
    pre(root, 0);

    int64_t answer = 0;

    for (int type = 0; type <= 1; type++) {
        for (int v = 1, q = 1; v <= n; v++) {
            if (!comp[type][v]) {
                int64_t qtd = dfs(v, q, type);
                compsz[type][q] = qtd;
                answer += (qtd-1) * qtd;
                q++;
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        int64_t cnt[2] = {0, 0};
        for (const auto &edge : g[v]) {
            int u = edge.first;

            if (u == parent[v]) {
                cnt[edge.second] += compsz[edge.second][comp[edge.second][u]] - sz[edge.second][v];
            } else {
                cnt[edge.second] += sz[edge.second][u];
            }
        }

        answer += cnt[0] * cnt[1];
    }

    cout << answer << "\n";

    return 0;
}


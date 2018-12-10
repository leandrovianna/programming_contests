// Codeforces - The Fair Nut and the Best Path - 1084D Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
vector<pair<int, int64_t>> g[N];
int64_t w[N], best[N], bestpath[N];

int64_t dfs(int v, int p) {
    int u;
    best[v] = w[v];

    int64_t path1 = 0, path2 = 0;

    for (const auto &edge : g[v]) {
        u = edge.first;    

        if (u == p) continue;

        int64_t c = dfs(u, v);
        best[v] = max(best[v], w[v] - edge.second + c);

        if (c - edge.second > path1) {
            path2 = path1;
            path1 = c - edge.second;
        } else if (c - edge.second > path2) {
            path2 = c - edge.second;
        }
    }

    bestpath[v] = w[v] + path1 + path2;

    return best[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u, v;
    int64_t c;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    dfs(1, 0);

    int64_t ans = 0;
    for (int v = 1; v <= n; v++) {
        ans = max({ans, best[v], bestpath[v]});
    }

    cout << ans << "\n";

    return 0;
}

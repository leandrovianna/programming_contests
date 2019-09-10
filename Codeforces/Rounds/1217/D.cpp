// Codeforces - Coloring Edges - 1217D
#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
vector<pair<int, int>> edges;
vector<int> g[N];
int color[N], ncolors;
int used[N];

void dfs(int v) {
    used[v] = 1;

    for (const auto &ed : g[v]) {
        int u = edges[ed].second;

        if (used[u] == 0) {
            color[ed] = 1;
            dfs(u);
        } else if (used[u] == 1) {
            ncolors = 2;
            color[ed] = 2;
        } else {
            color[ed] = 1;
        }
    }

    used[v] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    ncolors = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;

        g[u].push_back(edges.size());
        edges.push_back({u, v});
    }

    for (int v = 1; v <= n; v++) {
        if (used[v] == 0) {
            dfs(v);
        }
    }

    cout << ncolors << "\n";
    for (size_t i = 0; i < edges.size(); i++) {
        cout << color[i] << " ";
    }
    cout << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
set<int> g[N];
bool vis[N];
int sz[N];
int t[N], cnt = 0;
int ini[N];

int dfs(int v, int p) {
    vis[v] = true;

    t[cnt] = v;
    ini[v] = cnt;
    cnt++;

    sz[v] = 1;

    for (const auto &u : g[v]) {
        if (u == p) continue;

        sz[v] += dfs(u, v);
    }

    return sz[v];
}

int main() {
    ios::sync_with_stdio(false);
    int n, q;

    cin >> n >> q;
    for (int i = 2, p; i <= n; i++) {
        cin >> p;
        g[p].insert(i);
    }

    dfs(1, 0);

    for (int i = 0, u, k; i < q; i++) {
        cin >> u >> k;

        if (k > sz[u]) {
            cout << "-1\n";
        } else {
            cout << t[ini[u]+k-1] << "\n";
        }
    }

    return 0;
}

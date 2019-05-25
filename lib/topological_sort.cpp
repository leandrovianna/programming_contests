// Topological Sort
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
bool vis[N];
vector<int> ans;

void dfs(int v) {
    vis[v] = true;
    for (const auto &u : g[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
    ans.push_back(v);
}

void topological_sort(int n) {
    memset(vis, false, sizeof(vis));
    for (int v = 0; v < n; v++) {
        if (!vis[v]) {
            dfs(v);
        }
    }

    reverse(ans.begin(), ans.end());
    // Topological sort is on vector ans
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y; // x -> y
        g[x].push_back(y);
    }

    topological_sort(n);

    cout << "Topological Order:";
    for (int i = 0; i < n; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}

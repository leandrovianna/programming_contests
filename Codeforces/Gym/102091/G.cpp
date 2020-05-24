// Codeforces - Communication
#include <bits/stdc++.h>
using namespace std;

const int N = 250;
vector<int> g[N], gr[N];
bool used[N];
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for (const auto &u : g[v]) {
        if (!used[u]) {
            dfs1(u);
        }
    }

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (const auto &u : gr[v]) {
        if (!used[u]) {
            dfs2(u);
        }
    }
}

int kosaraju(int n) {
    memset(used, false, sizeof(used));
    order.clear();

    for (int v = 0; v < n; v++) {
        if (!used[v]){
            dfs1(v);
        }
    }

    memset(used, false, sizeof(used));
    component.clear();

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs2(v);
            ans++;
            component.clear();
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n, e;

    cin >> t;
    while (t--) {
        cin >> n >> e;
        for (int v = 0; v < n; v++) {
            g[v].clear();
            gr[v].clear();
        }

        for (int i = 0, a, b; i < e; i++) {
            cin >> a >> b;
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        cout << kosaraju(n) << "\n";
    }

    return 0;
}

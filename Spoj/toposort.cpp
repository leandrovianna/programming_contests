// Spoj - Topological Sort - TOPOSORT
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
vector<int> g[N];
bool vis[N];
vector<int> order;
int color[N];

bool has_cycle(int v) {
    color[v] = 1;
    for (const auto &u : g[v]) {
        if (color[u] == 1) {
            return true;
        }

        if (color[u] == 0) {
            if (has_cycle(u)) {
                return true;
            }
        }
    }
    color[v] = 2;

    return false;
}

void dfs(int v) {
    vis[v] = true;
    for (const auto &u : g[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }

    order.push_back(v);
}

void toposort(int n) {
    memset(vis, false, sizeof(vis));
    order.clear();

    for (int v = 0; v < n; v++) {
        if (!vis[n - 1 - v]) {
            dfs(n - 1 - v);
        }
    }

    reverse(order.begin(), order.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
    }

    for (int v = 0; v < n; v++) {
        sort(g[v].begin(), g[v].end(), greater<>());
    }

    memset(color, 0, sizeof(color));
    for (int v = 0; v < n; v++) {
        if (color[v] == 0) {
            if (has_cycle(v)) {
                cout << "Sandro fails.\n";
                return 0;
            }
        }
    }

    toposort(n);

    for (int i = 0; i < n; i++) {
        cout << 1 + order[i] << " ";
    }
    cout << "\n";

    return 0;
}

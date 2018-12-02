// AtCoder - Regular Contest 90 - People on a Line - D
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
typedef pair<int, int> ii;
vector<ii> g[N];
bool vis[N];
long long dis[N];

bool dfs(int v) {
    for (const auto &edge : g[v]) {
        int u = edge.first;

        if (vis[u]) {
            if (dis[u] != dis[v] + (long long) edge.second) {
                return false;
            }
        } else {
            vis[u] = true;
            dis[u] = dis[v] + (long long) edge.second;
            if (!dfs(u))
                return false;
        }
    }

    return true;
}


int main() {
    int n, m;
    int a, b, c;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        vis[i] = true;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, -c});
        vis[a] = false;
        vis[b] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            vis[i] = true;
            dis[i] = 0;
            if (dfs(i) == false) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}

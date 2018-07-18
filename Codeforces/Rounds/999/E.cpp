// Codeforces - Reachability from the Capital - 999E Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
vector<int> g[N];
int vis[N], vv = 1;

void dfs(int v) {
    vis[v] = vv;

    for (const auto &u : g[v]) {
        if (vis[u] != vv) {
            dfs(u);
        }
    }
}

vector<int> reach[N];
void dfs2(int v, int r) {
    vis[v] = vv;
    reach[r].push_back(v);

    for (const auto &u : g[v]) {
        if (vis[u] != 1 && vis[u] != vv) {
            dfs2(u, r);
        }
    }
}

int main() {
    int n, m, s;

    cin >> n >> m >> s;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }

    vv = 1;
    dfs(s);

    set<pair<int, int> > ss;

    int count = 0;

    for (int v = 1; v <= n; v++) {
        if (vis[v] != 1) {
            vv++;
            dfs2(v, v);
            ss.insert({reach[v].size(), v});
        } else {
            count++;
        }
    }

    vv++;
    int ans = 0;
    for (auto it = ss.rbegin(); it != ss.rend(); it++) {
        if (count == n) {
            break;
        }

        bool make = false;

        for (const auto &u : reach[it->second]) {
            if (vis[u] != 1 && vis[u] != vv) {
                vis[u] = vv;
                make = true;
                count++;
            }
        }

        if (make)
            ans++;
    }

    cout << ans << endl;
    return 0;
}

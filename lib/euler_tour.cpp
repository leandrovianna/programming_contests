// Euler Tour
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
vector<int> g[N];
int sz[N], ini[N], cnt = 0;
int64_t path[N];

int dfs(int v, int p) {
    ini[v] = cnt;
    path[cnt] = v;
    cnt++;
    sz[v] = 1;

    for (const auto &u : g[v]) {
        if (u == p) continue;

        sz[v] += dfs(u, v);
    }

    return sz[v];
}

int main() {
    int n;

    cin >> n;

    for (int i = 0, x, y; i < n-1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    for (int i = 0; i < cnt; i++) {
        cout << path[i] << " ";
    }
    cout << endl;

    int v = 1;
    // subarvore de v
    for (int i = ini[v]; i < ini[v]+sz[v]; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    
    return 0;
}

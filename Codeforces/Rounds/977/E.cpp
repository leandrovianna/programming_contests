#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int n;
bool vis[N];
vector<int> g[N];

template<typename T>
void debug(T value) {
#ifndef ONLINE_JUDGE
    cout << value << endl;
#endif
}

template <typename T, typename... Args>
void debug(T value, Args... args) {
#ifndef ONLINE_JUDGE
    cout << value;
    debug(args...);
#endif
}

bool dfs(int v) {
    debug("visiting ", v, " of degree ", g[v].size());

    vis[v] = true;

    bool ans = g[v].size() == 2U;

    for (const auto &u : g[v]) {
        if (vis[u] == false) {
            ans &= dfs(u);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, a, b;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    for (int v = 1; v <= n; v++) {
        if (vis[v] == false) {
            if (dfs(v))
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

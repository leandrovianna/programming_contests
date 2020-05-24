#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int p[N];
vector<string> pool;
int s[N];
char ch[N];
bool vis[N];
vector<int> topo;

void dfs(int v) {
    vis[v] = true;
    int u = p[v];
    if (!vis[u]) {
        dfs(u);
    }
    topo.push_back(v);
}

void topological_sort(int n) {
    memset(vis, false, sizeof(vis));
    for (int v = 2; v <= n; v++) {
        if (!vis[v]) {
            dfs(v);
        }
    }

    reverse(topo.begin(), topo.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }

    ch[1] = '#';
    s[1] = -1;
    for (int i = 2; i <= n; i++) {
        cin >> ch[i];
        s[i] = -1;
    }

    topological_sort(n);

    for (int i = 0; i < n; i++) {
        int v = topo[i];
        if (s[v] == -1) {
            s[v] = pool.size();
            pool.push_back(string(1, ch[v]));
        } else {
            pool[s[v]] += ch[v];
        }

        if (ch[p[v]] <= pool[s[v]].back() && ch[p[v]] <= pool[s[v]][0]) {
            if (s[p[v]] == -1 || pool[s[p[v]]] < pool[s[v]]) {
                s[p[v]] = s[v];
            }
        }
    }

    string ans = "";
    for (const auto &s : pool) {
        ans = max(s, ans);
    }

    ans.erase(remove(ans.begin(), ans.end(), '#'), ans.end());
    cout << ans << "\n";

    return 0;
}

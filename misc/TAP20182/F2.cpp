// TAP 2018/2 - Wikipedia Dominance
#include <bits/stdc++.h>
using namespace std;

const int N = 25;
bool vis[N];
int adj[N][N];
bool dfs(int v, int n) {
    vis[v] = true;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (vis[i])
                return true;
            if (dfs(i, n))
                return true;
        }
    }

    vis[v] = false;
    return false;
}

int main() {
    int n, m, cnt = 0;
    map<string, int> idx;
    string art, art2;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> art >> m;
        if (idx.count(art) == 0) {
            idx[art] = cnt++;
        }
        for (int j = 0; j < m; j++) {
            cin >> art2;
            if (idx.count(art2) == 0) {
                idx[art2] = cnt++;
            }

            adj[idx[art]][idx[art2]] = 1;
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            if (adj[i][j] == adj[j][i]) {
                adj[i][j] = 0;
                adj[j][i] = 0;
            }
        }
    }

    bool ans = false;
    for (int i = 0; i < n; i++) {
        ans |= dfs(i, n);
    }

    cout << "There is ";
    cout << (ans ? "a " : "no ");
    cout << "dominating circle." << endl;
    return 0;
}

//Codeforces - Peculiar apple-tree - 931D Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 100100, L = N;
int n;
vector<int> g[N];
int lvl[N], qtd[L];

void dfs(int v, int p) {
    lvl[v] = lvl[p] + 1;
    qtd[lvl[v]]++;

    for (const auto u : g[v]) {
        if (u == p) continue;

        dfs(u, v);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    int x;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    lvl[0] = 0;

    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i < L; i++) {
#ifndef ONLINE_JUDGE
        cout << qtd[i] << endl;
#endif
        if (qtd[i] % 2 == 1)
            ans++;
    }

    cout << ans << endl;
    return 0;
}

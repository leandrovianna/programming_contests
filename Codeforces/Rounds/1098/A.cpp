// Codeforces - Sum in the tree - 1098A Div1
#include <bits/stdc++.h>
using namespace std;

const int N = 100100, inf = 1000000000;
vector<int> g[N];
int a[N], s[N];

void dfs(int v, int p, int d) {
    int minChildren = inf;
    for (const auto &u : g[v]) {
        minChildren = min(minChildren, s[u]);
    }

    //cout << v << " " << " " << d << " " << minChildren << endl;

    if (s[v] == -1) {
        if (g[v].size() == 0)
            a[v] = 0;
        else
            a[v] = minChildren - s[p];
        s[v] = a[v] + s[p];
    } else {
        a[v] = s[v] - d;
    }

    //cout << "a: " << a[v] << endl;

    for (const auto &u : g[v]) {
        dfs(u, v, d + a[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;

    for (int i = 1, x; i < n; i++) {
        cin >> x;
        g[x-1].push_back(i);
    }

    for (int v = 0; v < n; v++) {
        cin >> s[v];
    }

    dfs(0, -1, 0);

    int64_t answer = 0;
    for (int v = 0; v < n; v++) {
        if (a[v] < 0) {
            answer = -1;
            break;
        }

        answer += a[v];
    }

    cout << answer << "\n";
    return 0;
}

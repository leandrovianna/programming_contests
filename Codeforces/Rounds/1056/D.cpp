// Codeforces - Decorate Apple Tree - 1056D
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int leafs[N];

int dfs(int x) {
    if (g[x].size() == 0)
        return leafs[x] = 1;

    int l = 0;
    for (const auto &u : g[x]) {
        l += dfs(u);
    }

    return leafs[x] = l;
}

int main() {
    int n;

    cin >> n;

    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
    }

    dfs(1);

    sort(leafs+1, leafs+n+1);

    for (int i = 1; i <= n; i++) {
        cout << leafs[i] << " ";
    }
    cout << endl;

    return 0;
}

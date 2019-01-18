#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
vector<int> g[N];
int64_t a[N], depth[N], sub[N], sum;

void dfs(int v, int p) {
    depth[v] = depth[p] + 1;
    sub[v] = a[v];

    for (const auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        sub[v] += sub[u];
    }
}

int64_t final_ans;

void find_answer(int v, int p, int64_t ans) {
    final_ans = max(ans, final_ans);

    for (const auto &u : g[v]) {
        if (u == p) continue;

        find_answer(u, v, ans + sum - 2 * sub[u]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0, x, y; i < n-1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    depth[0] = -1;
    dfs(1, 0);

    final_ans = 0;
    for (int v = 1; v <= n; v++) {
        final_ans += a[v] * depth[v];
    }

    find_answer(1, 0, final_ans);

    cout << final_ans << "\n";

    return 0;
}

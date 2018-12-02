#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10, M = 210;
int64_t dp[N][M][2];
int n, a[N];

int64_t solve(int i, int v, int ok) {
    cout << i << " " << v << " " << ok << endl;
    if (i == n+1)
        return 1;

    int64_t &ans = dp[i][v][ok];

    if (ans != -1)
        return ans;

    if (a[i] == -1) {
        for (int u = 1; u <= 200; u++) {
            if (ok && u < v)
                continue;

            if (a[i+1] == -1 || u <= max(v, a[i+1])) {
                ans += solve(i+1, u, (u <= v ? 0 : 1));
            }
        }
    } else {
        if (ok && a[i] < v)
            return 0;

        ans = solve(i+1, a[i], 1);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    a[0] = a[n+1] = 0;
    cout << solve(1, 0, 0) << endl;

    return 0;
}

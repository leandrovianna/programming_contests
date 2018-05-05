//Codejam 2018 - Round 1A - Ant Stack
#include <bits/stdc++.h>
using namespace std;

const int N = 120, W = 8 * 1010;
int64_t w[N];
int dp[N][W], n;
int used[N][W], vis = 1;

int solve(int i, int v) {
    if (i == n)
        return 0;

    int &ans = dp[i][v];

    if (used[i][v] == vis)
        return ans;
    used[i][v] = vis;

    ans = solve(i+1, v);

    if (w[i] <= v) {
        ans = max(ans, 1 + solve(i+1, min(v - w[i], 6 * w[i])));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }

        reverse(w, w+n);

        cout << "Case #" << ti << ": " << solve(0, W-1) << "\n";
        vis++;
    }
    return 0;
}

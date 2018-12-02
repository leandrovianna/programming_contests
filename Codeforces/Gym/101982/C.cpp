#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;
const int N = 1010;
const int64_t MOD = 998244353;
int64_t dp[N][N], a[N];
int s, k;

int64_t solve(int i, int j) {
    if (j == k) {
        return 1;
    }

    if (i == s) {
        return 0;
    }

    int64_t &ans = dp[i][j];

    if (ans != -1)
        return ans;

    ans = (solve(i+1, j) + a[i] * solve(i+1, j+1)) % MOD;

    return ans;
}

int main() {
    int n;

    cin >> n >> k;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    s = 0;
    for (const auto &p : cnt) {
        a[s++] = p.second;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;

    return 0;
}

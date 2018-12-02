#include <bits/stdc++.h>
using namespace std;

const int K = 1010, B = 130;
const int64_t mod = 1000000009;
int64_t poww[B];
int dp[B][K][B], k;

int solve(int bits, int n, int ones) {
    if (bits == -1) {
        return (n == 0 ? ones : 0);
    }

    int &ans = dp[bits][n][ones];

    if (ans != -1)
        return ans;

    ans = (solve(bits-1, (poww[bits] + n) % k, ones+1)
            + solve(bits-1, n, ones)) % mod;

    return ans;
}

int main() {
    int b;

    cin >> k >> b;

    poww[0] = 1;
    for (int i = 1; i < B; i++) {
        poww[i] = (poww[i-1] * 2LL) % k;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(b-1, 0, 0) << endl;
    return 0;
}

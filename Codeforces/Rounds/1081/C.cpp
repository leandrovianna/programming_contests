// Codeforces - Colorful Bricks - 1081C
#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 998244353;
const int N = 2010;
int64_t dp[N][N];
int n, k;
int64_t m;

int64_t solve(int i, int j) {
    if (i == n)
        return j == k;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = (solve(i+1, j+1) * (m-1) + solve(i+1, j)) % mod;
}

int main() {
    cin >> n >> m >> k;

    memset(dp, -1, sizeof(dp));
    cout << (m * solve(1, 0)) % mod << "\n";
    return 0;
}

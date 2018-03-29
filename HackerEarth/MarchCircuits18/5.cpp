//HackerEarth - Laser Tanks
#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
int n;
int64_t h[N][N], v[N][N], dp[N][N];
int64_t preH[N][N], preV[N][N];

int64_t solve(int i, int j) {
    if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int64_t &ans = dp[i][j];

    // int64_t localh = 0, localv = 0;

    // for (int k = i; k <= n; k++)
    //     localh += h[k][j];
    //
    // for (int k = 1; k <= i-1; k++)
    //     localv += v[k][j];

    ans = max(solve(i+1, j), preH[i][j] + preV[i-1][j] + solve(i, j-1));

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> h[i][j];
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int i = n; i >= 1; i--) {
            preH[i][j] = h[i][j] + preH[i+1][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            preV[i][j] = v[i][j] + preV[i+1][j];
        }
    }

    cout << solve(1, n) << endl;
    return 0;
}

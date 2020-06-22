// TAP 2018/2 - Speedy Delivery - E1
// DP Interativa
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n;
pair<int, int> loc[N];
int64_t dp[2][N][N];

int64_t dist(int i, int j) {
    return abs(loc[i].first - loc[j].first)
        + abs(loc[i].second - loc[j].second);
}

int idx(int x)
{
    return x&1;
}

int main() {
    cin >> n;

    loc[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> loc[i].first >> loc[i].second;
    }
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 0; i <= n; i++)
    {
        memset(dp[idx(i+1)], 0x3f3f3f3f, sizeof(dp[idx(i+1)]));
        for(int j = 0; j <= i; j++)
        {
            for(int k = 0; k <= i; k++)
            {
                dp[idx(i+1)][i][k] = min(dp[idx(i+1)][i][k], dp[idx(i)][j][k] + dist(i,j));
                dp[idx(i+1)][j][i] = min(dp[idx(i+1)][j][i], dp[idx(i)][j][k] + dist(i,k));
            }
        }
    }
    int64_t ans = LLONG_MAX; 
    for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                ans = min(ans,dp[idx(n+1)][i][j]);

    printf("%lld blocks traveled.\n", ans);
    return 0;
}

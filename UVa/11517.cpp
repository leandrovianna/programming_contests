// UVA - 11517 - Exact Change
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110, W = 2 * 10010, INF = 1000000000;
    int t, m, n, coin[N];
    int dp[W];

    cin >> t;

    while (t--) {
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            cin >> coin[i];
        }

        dp[0] = 0;
        for (int w = 1; w < W; w++) {
            dp[w] = INF;
        }

        for (int i = 0; i < n; i++) {
            int c = coin[i];
            for (int w = W-1; w >= 0; w--) {
                if (w - c >= 0) {
                    dp[w] = min(dp[w], 1 + dp[w-c]);
                }
            }
        }

        for (int w = m; w < W; w++) {
            if (dp[w] != INF) {
                cout << w << " " << dp[w] << "\n";
                break;
            }
        }
    }
    return 0;
}

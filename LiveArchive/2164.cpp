// Live Archive - LATAM 2000 - Cable Network - 2164
#include <bits/stdc++.h>
using namespace std;

const int N = 200;
struct edge {
    int to, from, cost;
} edges[N];

const int M = 21;

int n, t, k;
int dp[1 << M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int ti = 1; cin >> n >> t, n; ti++) {
        k = 0; // number of edges
        for (int i = 0, x; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                cin >> x;
                edges[k++] = {i, j, x};
            }
        }

        int ans = 1e9;

        for (int mask = 1; mask < (1 << (n+1)); mask++) {
            dp[mask] = 1e9;
        }

        dp[1] = 0;

        for (int i = 0; i < k; i++) {
            for (int mask = 1; mask < (1 << (n+1)); mask++) {
                if ((mask & (1 << edges[i].from)) != (mask & (1 << edges[i].to)))
                    dp[mask | (1 << edges[i].from) | (1 << edges[i].to)] = min(dp[mask] + edges[i].cost,
                        dp[mask | (1 << edges[i].from) | (1 << edges[i].to)]);
            }
        }

        for (int mask = 1; mask < (1 << (n+1)); mask++) {
            dp[mask] += t * (n - __builtin_popcount(mask) + 1);
        }

        for (int mask = 1; mask < (1 << (n+1)); mask++) {
            ans = min(ans, dp[mask]);
        }

        cout << "Cable Net #" << ti << "\n";
        cout << n * t << "\n" << ans << "\n\n";
    }
    return 0;
}

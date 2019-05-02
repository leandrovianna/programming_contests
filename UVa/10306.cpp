#include <bits/stdc++.h>
using namespace std;

struct ecoin {
    int x, y;
};

int main() {
    const int N = 45, W = 310,
          INF = 1000000000;
    ecoin coin[N];
    int dp[W][W];
    int n, m, s;

    cin >> n;

    while (n--) {
        cin >> m >> s;

        for (int i = 0; i < m; i++) {
            cin >> coin[i].x >> coin[i].y;
        }

        for (int x = 0; x <= s; x++) {
            for (int y = 0; y <= s; y++) {
                dp[x][y] = INF;
            }
        }

        dp[0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int x = 0; x <= s; x++) {
                for (int y = 0; y <= s; y++) {
                    if (x == 0 && y == 0) continue;

                    int xi = coin[i].x, yi = coin[i].y;
                    if (x - xi >= 0 && y - yi >= 0)
                        dp[x][y] = min(dp[x][y], 1 + dp[x-xi][y-yi]);
                }
            }
        }

        int ans = INF;
        for (int x = 0; x <= s; x++) {
            for (int y = 0; y <= s; y++) {
                if (x == 0 && y == 0) continue;

                if (fabs(sqrt(x * x + y * y) - s) < 1e-9) {
                    ans = min(ans, dp[x][y]);
                }
            }
        }

        if (ans == INF)
            cout << "not possible\n";
        else
            cout << ans << "\n";
    }
    return 0;
}

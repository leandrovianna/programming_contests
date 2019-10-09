// Codeforces - Timetable - 946D
#include <bits/stdc++.h>
using namespace std;

const int N = 510, inf = 1e9;
int n, m, k;
bool b[N][N];
int best[N][N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            b[i][j] = (ch == '1');
        }
    }

    for (int i = 0; i < n; i++) {
        int tot = 0;
        for (int p = 0; p < m; p++) {
            if (b[i][p]) tot++;
        }

        for (int x = 0; x <= m; x++) {
            best[i][x] = inf;
        }

        best[i][tot] = 0;
        for (int p = 0; p < m; p++) {
            if (!b[i][p]) continue;

            int cnt = 0;
            for (int q = p; q < m; q++) {
                if (b[i][q]) cnt++;
                else continue;

                best[i][tot - cnt] = 
                    min(best[i][tot - cnt], q - p + 1);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = inf;
        }
    }

    dp[0][k] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int x = 0; j+x <= k; x++) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j+x] + best[i][x]);
            }
        }
    }

    int mx = inf;
    for (int j = 0; j <= k; j++) {
        mx = min(mx, dp[n][j]);
    }

    cout << mx << "\n";

    return 0;
}

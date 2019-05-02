// UVA Online Judge - 10819 - Trouble of 13-Dots
#include <bits/stdc++.h>
using namespace std;

const int M = 10210, N = 110;
int n, m;
int dp[N][M], used[N][M], vis = 1;

struct product {
    int p, f;
} a[N];

const int CREDIT_CARD_LIMIT = 2000;
const int BONUS = 200;
const int INF = N * 10;

int solve(int i, int j) {
    if (j > m+BONUS)
        return -INF;

    if (i == n) {
        if (j <= m || j > CREDIT_CARD_LIMIT)
            return 0;
        else
            return -INF;
    }

    int &ans = dp[i][j];

    if (used[i][j] != vis) {
        used[i][j] = vis;

        ans = max(solve(i + 1, j),
                solve(i + 1, j + a[i].p) + a[i].f);
    }

    return ans;
}

int main() {
    while (cin >> m >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i].p >> a[i].f;
        }

        vis++;
        cout << max(0, solve(0, 0)) << "\n";
    }
    return 0;
}

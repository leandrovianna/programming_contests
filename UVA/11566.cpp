// UVA - Let's Yum Cha! - 11566
#include <bits/stdc++.h>
using namespace std;

const int K = 110;
int n, x, t, k;

struct dim {
    int p, f;
} a[K];

const int N = 15, M = 25;
const int X = N * 110;
int dp[K][M][X], used[K][M][X], vis;
const int INF = 1000000000;

int ceili(double x) {
    return static_cast<int>(ceil(x));
}

int solve(int i, int j, int m) {
    const int budget = (n + 1) * x;
    int cost = (n+1) * t + m;
    cost += ceili(cost / 10.0);

    if (cost > budget || j < 0)
        return -INF;

    if (j == 0 || i == k) {
        return (cost <= budget) ? 0 : -INF;
    }

    int &ans = dp[i][j][m];

    if (used[i][j][m] == vis)
        return ans;
    used[i][j][m] = vis;

    ans = -INF;
    for (int tm = 0; tm <= 2; tm++) {
        ans = max(ans, 
                solve(i + 1, j - tm, m + a[i].p * tm) + a[i].f * tm);
    }

    return ans;
}

int main() {
    cout << fixed;
    cout << setprecision(2);

    while (cin >> n >> x >> t >> k, n || x || t || k) {
        for (int i = 0; i < k; i++) {
            cin >> a[i].p;
            int sum = 0;
            for (int j = 0, y; j < n+1; j++) {
                cin >> y;
                sum += y;
            }
            a[i].f = sum;
        }
        
        vis++;
        double ans = solve(0, 2 * (n+1), 0) / static_cast<double>(n+1);
        cout << ans << '\n';
    }
    return 0;
}

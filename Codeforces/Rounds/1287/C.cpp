// Codeforces - Garland - 1287C
#include <bits/stdc++.h>
using namespace std;

const int N = 110, inf = 1e9;
int p[N], dp[N][N][N][2], n;

int solve(int i, int even, int odd, int last) {
    if (i == n) {
        assert(even == 0 && odd == 0);
        return 0;
    }

    int &ans = dp[i][even][odd][last];
    if (ans != -1)
        return ans;

    assert(even > 0 || odd > 0 || p[i] != 0);

    if (p[i] != 0) {
        int inc = (i > 0 && p[i] % 2 != last) ? 1 : 0;
        ans = inc + solve(i+1, even, odd, p[i] % 2);
    } else {
        ans = inf;

        if (even > 0) {
            int inc = (i > 0 && last != 0) ? 1 : 0;
            ans = min(ans, inc + solve(i+1, even-1, odd, 0));
        }

        if (odd > 0) {
            int inc = (i > 0 && last != 1) ? 1 : 0;
            ans = min(ans, inc + solve(i+1, even, odd-1, 1));
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int countEven = n / 2, countOdd = n / 2 + n % 2;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] != 0)
            p[i] % 2 == 0 ? countEven-- : countOdd--;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, countEven, countOdd, 0) << "\n";

    return 0;
}

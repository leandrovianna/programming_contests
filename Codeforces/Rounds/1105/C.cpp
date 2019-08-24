// Codeforces - Ayoub and Lost Array - 1105C
#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int c0, c1, c2; // count of numbers mod 3 equal to 0, 1 and 2
const int N = 200100;
const int MOD = 1000000007;
int64_t dp[N][10];

int64_t solve(int i, int mod) {
    if (i == n)
        return (mod == 0 ? 1 : 0);

    if (dp[i][mod] != -1)
        return dp[i][mod];

    auto &ans = dp[i][mod];

    ans = ((solve(i+1, mod) * c0
        + solve(i+1, (mod + 1) % 3) * c1) % MOD
        + solve(i+1, (mod + 2) % 3) * c2) % MOD;

    return ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n >> l >> r;

    c0 = r / 3 - l / 3 + (l % 3 == 0);
    c1 = c2 = c0 - 1;

    int x = l;
    while (x % 3 != 0) {
        if (x % 3 == 1)
            c1++;
        else
            c2++;
        x++;
    }

    x = r;
    while (x % 3 != 0) {
        if (x % 3 == 1)
            c1++;
        else
            c2++;
        x--;
    }

    cout << solve(0, 0) << endl;
    return 0;
}

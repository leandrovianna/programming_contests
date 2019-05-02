// UVA - Divisible Group Sums - 10616
#include <bits/stdc++.h>
using namespace std;

const int N = 200, D = 20, M = 11;
int64_t a[N];
int64_t dp[N][D][M];
int used[N][D][M], vis = 1;
int n, d;

int mod(int v, int m) {
    return (v < 0) ? (v % m + m) % m : v % m;
}

int64_t solve(int i, int j, int k) {
    if (k == 0)
        return (j == 0) ? 1 : 0;

    if (i == n)
        return 0;

    int64_t &ans = dp[i][j][k];

    if (used[i][j][k] == vis) {
        return ans;
    }
    used[i][j][k] = vis;

    ans = solve(i + 1, j, k) 
        + solve(i + 1, mod(j + a[i], d), k - 1);
    
    return ans;
}

int main() {
    int q, m;

    for (int ti = 1; cin >> n >> q; ti++) {
        if (n == 0 && q == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << "SET " << ti << ":\n";
        for (int qi = 1; qi <= q; qi++) {
            cin >> d >> m;

            cout << "QUERY " << qi << ": ";
            vis++;
            cout << solve(0, 0, m) << "\n";
        }
    }
    return 0;
}

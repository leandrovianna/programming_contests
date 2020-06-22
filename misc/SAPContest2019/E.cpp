#include <bits/stdc++.h>
using namespace std;

const int D = 1010, Q = 10;
const int64_t inf = 1e18;
int64_t p[D], c, dp[D][Q];
int used[D][Q], vis;
int d;

int64_t solve(int i, int j) {
    assert(0 <= j && j <= 5);

    int64_t &ans = dp[i][j];

    if (i == d) return ans = 0;

    if (used[i][j] == vis)
        return ans;

    ans = solve(i+1, j);

    for (int k = 1; j+k <= 5; k++) {
        ans = max(ans, p[i] * k * -100 - c + solve(i+1, j+k));
    }

    for (int k = 1; j-k >= 0; k++) {
        ans = max(ans, p[i] * k * 100 - c + solve(i+1, j-k));
    }

    used[i][j] = vis;
    return ans;
}

void walk(int i, int j) {
    if (i == d) return;

    cout << "day " << i << ": ";

    int64_t &ans = dp[i][j];
    if (ans == dp[i+1][j]) {
        cout << "do nothing" << endl;
        walk(i+1, j);
    } else if (j < 5 && ans == p[i] * -100 - c + dp[i+1][j+1]) {
        cout << "buy by " << p[i] << endl;
        walk(i+1, j+1);
    } else if (j > 0 && ans == p[i] * 100 - c + dp[i+1][j-1]) {
        cout << "sell by " << p[i] << endl;
        walk(i+1, j-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n >> d >> c;

    string cod, best = "None";
    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> cod;
        for (int j = 0; j < d; j++) {
            cin >> p[j];
        }

        vis++;
        int64_t v = solve(0, 0);
        if (v > ans) {
            ans = v;
            best = cod;
        }
    }

    cout << best << " " << ans << "\n";
    return 0;
}

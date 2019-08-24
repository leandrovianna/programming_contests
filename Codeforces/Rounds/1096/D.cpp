// Codeforces - Easy Problem - 1096D
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int64_t a[N];
const int64_t inf = 1e18;
int n;
string s;
int64_t dp[N][5];

int64_t solve(int i, int st) {
    if (st == 4) {
        return inf;
    }

    if (i == n) {
        return 0;
    }

    int64_t &ans = dp[i][st];
    
    if (ans != -1) {
        return ans;
    }

    ans = a[i] + solve(i+1, st);

    if (s[i] == 'h' && st == 0) {
        ans = min(ans, solve(i+1, 1));
    } else if (s[i] == 'a' && st == 1) {
        ans = min(ans, solve(i+1, 2));
    } else if (s[i] == 'r' && st == 2) {
        ans = min(ans, solve(i+1, 3));
    } else if (s[i] == 'd' && st == 3) {
        ans = min(ans, solve(i+1, 4));
    } else {
        ans = min(ans, solve(i+1, st));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << "\n";
    return 0;
}

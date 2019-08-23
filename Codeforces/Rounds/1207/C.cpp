// Codeforces - 1207C - Gas Pipeline
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
const int64_t inf = 1e18;
int64_t dp[N][2], a, b;
int used[N][2], vis;
int s[N];
int n;

int64_t solve(int i, int h) {
    if (i == n) {
        if (h == 0)
            return 0;
        else
            return inf;
    }

    if (s[i] == 1 && h == 0) {
        return inf;
    }

    int64_t &ans = dp[i][h];

    if (used[i][h] == vis) {
        return ans;
    }
    used[i][h] = vis;

    ans = a + (h+1) * b + solve(i+1, h);

    if (s[i] == 0) {
        if (h == 0)
            ans = min(ans, 2 * a + 2 * b + solve(i+1, h+1));
        else if (h == 1)
            ans = min(ans, 2 * a + b + solve(i+1, h-1));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string st;
    cin >> t;

    while (t--) {
        cin >> n >> a >> b;

        cin >> st;
        for (int i = 0; i < n; i++) {
            s[i] = st[i] - '0';
        }
        s[n] = 0;

        vis++;
        cout << b + solve(0, 0) << "\n";
    }
    return 0;
}

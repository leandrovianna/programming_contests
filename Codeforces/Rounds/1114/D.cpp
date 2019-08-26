// Codeforces - Flood Fill - 1114D Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 5010, inf = 1e9;
int c[N], n;
int dp[N][N][2];

int solve(int l, int r, int color) {
    if (l == 0 && r == n+1)
        return 0;

    int &ans = dp[l][r][color];

    if (ans != -1)
        return ans;

    int currColor = (color == 0 ? c[l] : c[r]);

    ans = inf;

    if (l > 0) {
        if (currColor == c[l-1])
            ans = min(ans, solve(l-1, r, 0));
        else
            ans = min(ans, 1 + solve(l-1, r, 0));
    }

    if (r < n+1) {
        if (currColor == c[r+1])
            ans = min(ans, solve(l, r+1, 1));
        else
            ans = min(ans, 1 + solve(l, r+1, 1));
    }

    return ans;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    c[0] = c[1];
    c[n+1] = c[n];

    memset(dp, -1, sizeof(dp));

    int answer = N;
    for (int i = 1; i <= n; i++) {
        answer = min(answer, solve(i, i, 0));
    }

    cout << answer << "\n";
    return 0;
}

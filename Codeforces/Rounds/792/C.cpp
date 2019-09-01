// Codeforces - Divide by Three - 792C
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9, N = 100100;
int num[N], n;
int dp[N][3][2];

int solve(int i, int j, int lead) {
    int &ans = dp[i][j][lead];

    if (i == n) {
        if (lead == 0 || j > 0)
            return ans = inf;
        else
            return ans = 0;
    }

    if (ans != -1)
        return ans;

    ans = 1 + solve(i+1, j, lead);

    if (lead == 1 || num[i] != 0) {
        ans = min(ans, solve(i+1, (j + num[i]) % 3, 1));
    }

    return ans;
}

void printAnswer(int i, int j, int lead) {
    int &ans = dp[i][j][lead];

    if (i == n) {
        cout << "\n";
        return;
    }

    if (ans == 1 + dp[i+1][j][lead]) {
        printAnswer(i+1, j, lead);
    } else if (ans == dp[i+1][(j + num[i]) % 3][1]) {
        cout << num[i];
        printAnswer(i+1, (j + num[i]) % 3, 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    bool has_zero = false;
    n = s.size();
    for (int i = 0; i < n; i++) {
        num[i] = s[i] - '0';

        if (num[i] == 0) {
            has_zero = true;
        }
    }

    memset(dp, -1, sizeof(dp));
    int r = solve(0, 0, 0);

    if (r == inf) {
        cout << (has_zero ? "0" : "-1") << "\n";
    } else {
        printAnswer(0, 0, 0);
    }

    return 0;
}

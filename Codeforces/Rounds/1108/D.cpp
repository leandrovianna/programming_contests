// Codeforces - Diverse Garland - 1108D - Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 200100, inf = 1000000000;
int dp[N][3];
int n;
string s;

int _typeof(char c) {
    switch (c) {
        case 'R':
            return 0;
        case 'G':
            return 1;
        case 'B':
            return 2;
    }

    return -1;
}

int solve(int i, int t) {
    int &ans = dp[i][t];
    if (ans != -1)
        return ans;

    if (i == n)
        return ans = 0;

    ans = inf;

    for (int ti = 0; ti < 3; ti++) {
        if (ti == t) continue;
        ans = min(ans, 1 + solve(i+1, ti));
    }

    if (_typeof(s[i]) != t)
        ans = min(ans, solve(i+1, _typeof(s[i])));

    return ans;
}

void print_best(int i, int t) {
    if (i == n) {
        cout << "\n";
        return;
    }

    int &ans = dp[i][t];

    for (int ti = 0; ti < 3; ti++) {
        if (ti == t) continue;

        if (ans == 1 + dp[i+1][ti]) {
            switch (ti) {
                case 0:
                    cout << 'R';
                    break;
                case 1:
                    cout << 'G';
                    break;
                case 2:
                    cout << 'B';
                    break;
            }

            print_best(i+1, ti);
            return;
        }
    }

    cout << s[i];
    print_best(i+1, _typeof(s[i]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    memset(dp, -1, sizeof(dp));

    cout << solve(0, (_typeof(s[0]) == 0 ? 1 : 0)) << "\n";
    print_best(0, _typeof(s[0]) == 0 ? 1 : 0);

    return 0;
}

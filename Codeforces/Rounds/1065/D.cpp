// Codeforces - Three Pieces - 1065D Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int a[N][N], n;
pair<int, int> dp[N][N][N*N][3];
bool used[N][N][N*N][3];
const pair<int, int> d[8] = {{2,1}, {-2,-1}, {-2,1}, {2,-1}, {1,2}, {-1,-2}, {1,-2}, {-1,2}};

bool on(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

pair<int, int> go(int x, int y, int i, int t, int newt);

pair<int, int> solve(int x, int y, int i, int t) {
    if (i == n*n)
        return {0, 0};

    auto &ans = dp[x][y][i][t];
    if (used[x][y][i][t])
        return ans;
    used[x][y][i][t] = true;

    ans.first = ans.second = 1e9;

    for (int k = 0; k < 8; k++) {
        ans = min(ans, go(x + d[k].first, y + d[k].second, i, t, 0));
    }

    for (int k = 1; k < N; k++) {
        for (int d1 = -1; d1 <= 1; d1 += 2) {
            for (int d2 = -1; d2 <= 1; d2 += 2) {
                ans = min(ans, go(x + k * d1, y + k * d2, i, t, 1));
            }
        }
    }

    for (int k = 1; k < N; k++) {
        for (int d1 = -1; d1 <= 1; d1 += 2) {
            ans = min(ans, go(x + k * d1, y, i, t, 2));
            ans = min(ans, go(x, y + k * d1, i, t, 2));
        }
    }

    return ans;
}

pair<int, int> go(int x, int y, int i, int t, int newt) {
    if (!on(x, y))
        return {1e9, 1e9};

    auto p = solve(x, y, (a[x][y] == i+1 ? i+1 : i), newt);
    p.first++;
    if (newt != t) {
        p.first++;
        p.second++;
    }

    return p;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    pair<int, int> ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1) {
                ans = min({solve(i, j, 1, 0), solve(i, j, 1, 1), solve(i, j, 1, 2)});
                break;
            }

    cout << ans.first << " " << ans.second << endl;

    return 0;
}

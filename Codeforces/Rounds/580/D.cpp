// Codeforces - Kefa and Dishes - 580D Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
int64_t a[N], adj[N][N], dp[N][1 << N];
int used[N][1 << N], test;

int64_t solve(int i, int vis) {
    int cnt = __builtin_popcount(vis);

    if (cnt == m)
        return a[i];

    int64_t &ans = dp[i][vis];
    if (used[i][vis] == test)
        return ans;
    used[i][vis] = test;

    ans = 0;

    for (int j = 0; j < n; j++) {
        if (!(vis & (1 << j))) {
            ans = max(ans, a[i] + adj[i][j] + solve(j, vis | (1 << j)));
        }
    }

    return ans;
}

int main() {
    int k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0, x, y; i < k; i++) {
        cin >> x >> y;
        x--;
        y--;
        cin >> adj[x][y];
    }

    int64_t answer = 0;
    test++;

    for (int i = 0; i < n; i++) {
        answer = max(answer, solve(i, 1 << i));
    }

    cout << answer << endl;
    return 0;
}

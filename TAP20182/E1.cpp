// TAP 2018/2 - Speedy Delivery - E1
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n;
pair<int, int> loc[N];
int64_t memo[N][N][N];

int64_t dist(int i, int j) {
    return abs(loc[i].first - loc[j].first)
        + abs(loc[i].second - loc[j].second);
}

int64_t solve(int i, int j, int k) {
    if (i > n)
        return 0;

    int64_t &ans = memo[i][j][k];

    if (ans != -1)
        return ans;

    ans = min(dist(i, j) + solve(i+1, i, k),
            dist(i, k) +  solve(i+1, j, i));

    return ans;
}

int main() {
    cin >> n;

    loc[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> loc[i].first >> loc[i].second;
    }
    memset(memo, -1, sizeof(memo));
    cout << solve(1, 0, 0) << " blocks traveled." << endl;
    return 0;
}

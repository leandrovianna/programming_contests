// UVa Online Judge - The bridges of Kolsberg - 1172
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
string type1[N], type2[N];
int64_t v1[N], v2[N];

pair<int64_t, int> operator+(pair<int64_t, int> a, pair<int64_t, int> b) {
    return {a.first + b.first, a.second + b.second};
}

pair<int64_t, int> dp[N][N];
int used[N][N], vis = 1;

int n, m;

pair<int64_t, int> get_best(pair<int64_t, int> p1, pair<int64_t, int> p2) {
    if (p1.first < p2.first) {
        return p2;
    } else if (p1.first > p2.first) {
        return p1;
    } else if (p1.second < p2.second) {
        return p1;
    } else {
        return p2;
    }
}

pair<int64_t, int> solve(int i, int j) {
    if (i == n || j == m)
        return {0, 0};

    auto &ans = dp[i][j];
    if (used[i][j] == vis) {
        return ans;
    }
    used[i][j] = vis;

    auto ans1 = solve(i+1, j), ans2 = solve(i, j+1);
    ans = get_best(ans1, ans2);

    if (type1[i] == type2[j]) {
        ans = get_best(ans, pair<int64_t, int>{v1[i] + v2[j], 1} + solve(i+1, j+1));
    }

    return ans;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        cin >> n;
        string none;
        for (int i = 0; i < n; i++) {
            cin >> none >> type1[i] >> v1[i];
        }

        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> none >> type2[i] >> v2[i];
        }

        vis++;
        auto ans = solve(0, 0);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

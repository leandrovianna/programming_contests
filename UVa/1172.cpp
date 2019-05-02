// UVa Online Judge - The bridges of Kolsberg - 1172
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
map<string, int> idx;

const int N = 1010;
int type1[N], type2[N];
int64_t v1[N], v2[N];

bool operator<(pair<int64_t, int> a, pair<int64_t, int> b) {
    return a.first < b.first
        || (a.first == b.first && a.second >= b.second);
}

pair<int64_t, int> operator+(pair<int64_t, int> a, pair<int64_t, int> b) {
    return {a.first + b.first, a.second + b.second};
}

pair<int64_t, int> dp[N][N];
int used[N][N], vis = 1;

int n, m;

pair<int64_t, int> solve(int i, int j) {
    if (i == n || j == m)
        return {0, 0};

    auto &ans = dp[i][j];
    if (used[i][j] == vis) {
        return ans;
    }
    used[i][j] = vis;

    ans = max(solve(i+1, j), solve(i, j+1));

    if (type1[i] == type2[j]) {
        ans = max(ans, pair<int64_t, int>{v1[i] + v2[j], 1} + solve(i+1, j+1));
    }

    return ans;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        idx.clear();
        cnt = 0;
        int x;
        string str;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> str >> str >> x;
            if (idx.count(str) == 0)
                idx[str] = cnt++;

            type1[i] = idx[str];
            v1[i] = x;
        }

        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> str >> str >> x;
            if (idx.count(str) == 0)
                idx[str] = cnt++;

            type2[i] = idx[str];
            v2[i] = x;
        }

        vis++;
        auto ans = solve(0, 0);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

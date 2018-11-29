// TAP 2018/2 - Festival
// URI -  2881
// dp more memory
#include <bits/stdc++.h>
using namespace std;

struct show {
    int i, f, o, p, j;

    bool operator< (const show &other) {
        return this->i < other.i || (this->i == other.i && this->j < other.j);
    }
};

vector<show> shows;

const int T = 90000, V = 1 << 11;
const int INF = 1000000000;
int dp[T][V];
bool used[T][V];
int n;
int solve(int t, int vis) {
    if (used[t][vis])
        return dp[t][vis];
    used[t][vis] = true;

    int &ans = dp[t][vis];

    auto it = lower_bound(shows.begin(), shows.end(), show{t-1, 0, 0, 0, 1100});

    ans = (vis == (1 << n) - 1 ? 0 : -INF);
    if (it != shows.end()) {
        for (; it != shows.end(); it++) {
            ans = max(ans, it->o + solve(it->f, vis | (1 << it->p)));
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0, m; i < n; i++) {
        cin >> m;
        for (int j = 0, ini, fim, o; j < m; j++) {
            cin >> ini >> fim >> o;
            shows.push_back({ini, fim, o, i, i * n + j});
        }
    }

    sort(shows.begin(), shows.end());
    int ans = solve(1, 0);
    cout << (ans < 0 ? -1 : ans) << "\n";
    return 0;
}

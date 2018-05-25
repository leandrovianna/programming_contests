#include <bits/stdc++.h>
using namespace std;

const int M = 550;
int n, m, k;
int64_t group[M];
int64_t f[M];

int64_t solve(vector<int> comb) {
    int64_t mask = 0;
    for (const auto &x : comb) {
        mask |= (1LL << x);
    }

    int64_t used = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        if (!(mask & group[i])) {
            used |= group[i];
            ans += f[i];
        }
    }

    // nao coloquei ngm no time 2
    if (used == 0)
        return 0;

    for (int i = 0; i < m; i++) {
        if (!(used & group[i])) {
            ans += f[i];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> k >> f[i];
        for (int j = 0, x; j < k; j++) {
            cin >> x;
            x--; //[0, n-1]
            group[i] |= (1LL << x);
        }
    }

    int64_t ans = 0;
    for (int a = 0; a < n; a++) {
        ans = max(ans, solve({a}));
        for (int b = 0; b < n; b++) {
            ans = max(ans, solve({a, b}));
            for (int c = 0; c < n; c++) {
                ans = max(ans, solve({a, b, c}));
            }
        }
    }

    cout << ans << endl;
    return 0;
}

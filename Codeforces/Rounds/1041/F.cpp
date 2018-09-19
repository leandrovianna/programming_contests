// Codeforces - Ray in the Tube - 1041F Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    const int N = 100 * 1000 + 10;
    const int M = 1000 * 1000 * 1000;
    int x[2][N], y1, y2;

    cin >> n >> y1;

    for (int i = 0; i < n; i++) {
        cin >> x[0][i];
    }

    cin >> m >> y2;

    for (int i = 0; i < m; i++) {
        cin >> x[1][i];
    }

    int ans = 2;

    for (int dx = 1; dx < M; dx *= 2) {
        int mod = 2 * dx;
        map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            cnt[x[0][i] % mod]++;
        }

        for (int i = 0; i < m; i++) {
            cnt[(x[1][i] + dx) % mod]++;
        }

        for (const auto &item : cnt) {
            ans = max(ans, item.second);
        }
    }

    cout << ans << endl;
    return 0;
}

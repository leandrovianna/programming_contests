// Codeforces - Zmei Gorynich - 1217B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, x;

    cin >> t;

    while (t--) {
        cin >> n >> x;

        int maxd = 0, mindiff = 1e9;
        for (int i = 0, d, h; i < n; i++) {
            cin >> d >> h;
            maxd = max(maxd, d);
            mindiff = min(mindiff, h - d);
        }

        if (maxd >= x) {
            cout << "1\n";
        } else if (mindiff >= 0) {
            cout << "-1\n";
        } else {
            int ans = (x - maxd + abs(mindiff) - 1) / abs(mindiff);
            cout << ans + 1 << "\n";
        }
    }
    return 0;
}

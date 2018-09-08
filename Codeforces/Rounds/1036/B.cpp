// Codeforces - Diagonal Walking v.2 - 1036B - EduRound
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    int64_t n, m, d, k;

    cin >> q;

    while (q--) {
        cin >> n >> m >> k;
        d = min(n, m) + abs(n - m);

        if (k < d)
            cout << -1 << endl;
        else {
            int64_t ans = k - (k - n) % 2 - (k - m) % 2;
            cout << ans << endl;
        }
    }
    return 0;
}

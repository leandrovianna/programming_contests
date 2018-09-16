// Codeforces - Glider - 1041D Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int64_t x[N], y[N], pref[N];;

int64_t sum(int64_t y0, int n) {
    auto pos = lower_bound(y, y+n, y0) - y;

    if (pos == n) {
        return pref[n-1];
    } else {
        return (pos > 0 ? pref[pos-1] : 0) + max((int64_t) 0, y0 - x[pos]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64_t h;

    cin >> n >> h;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        pref[i] = (i == 0 ? 0 : pref[i-1]) + (y[i] - x[i]);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        int64_t lo = x[i], hi = 10LL * 1000 * 1000 * 1000;
        int64_t mid, l_ans = hi;

        while (lo <= hi) {
            mid = (lo + hi) / 2LL;

            int64_t h2 = h - (mid - x[i]) + sum(mid, n) - sum(x[i] - 1, n);

            if (h2 <= 0) {
                hi = mid-1;
                if (h2 == 0) {
                    l_ans = mid;
                }
            } else if (h2 > 0) {
                lo = mid+1;
            }
        }

        ans = max(ans, l_ans - x[i]);
    }

    cout << ans << endl;
    return 0;
}

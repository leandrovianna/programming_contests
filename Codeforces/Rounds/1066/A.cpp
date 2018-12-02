// Codeforces - Vova and Train - 1066A Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    int64_t f, v, l, r;

    cin >> t;

    while (t--) {
        cin >> f >> v >> l >> r;

        int64_t lo = 1, hi = f, mid;
        int64_t i = f, j = 0;

        while (lo <= hi) {
            mid = (hi - lo) / 2 + lo;
            if (mid * v >= l) {
                i = min(mid, i);
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        lo = 1;
        hi = f;
        while (lo <= hi) {
            mid = (hi - lo) / 2 + lo;
            if (mid * v <= r) {
                j = max(mid, j);
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        cout << (f / v) - (j - i + 1) << "\n";
    }
    return 0;
}

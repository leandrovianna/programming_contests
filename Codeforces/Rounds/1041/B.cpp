// Codeforces - Buying a TV Set - 1041B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t a, b, x, y;

    cin >> a >> b >> x >> y;

    int64_t g = __gcd(x, y);
    x /= g;
    y /= g;

    int64_t ans = min(a / x, b / y);
    cout << ans << "\n";

    /*
    int64_t lo = 1, hi = max(a / x + 1, b / y + 1), mid;
    int64_t ans = 0;

    while (lo <= hi) {
        mid = (hi - lo) / 2LL + lo;

        if (x * mid <= a && y * mid <= b) {
            lo = mid+1;
            ans = max(ans, mid);
        } else {
            hi = mid-1;
        }
    }

    cout << ans << "\n";
    */

    return 0;
}

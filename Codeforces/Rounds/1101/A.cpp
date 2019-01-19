// Codeforces - Minimum Integer - 1101A Edu Round 58
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    int64_t l, r, d, ans;

    cin >> q;

    while (q--) {
        cin >> l >> r >> d;

        ans = d;

        if (l <= d && d <= r) {
            int64_t x = (r / d) * d;
            if (x <= r)
                x += d;
            ans = x;
        }

        cout << ans << "\n";
    }
    return 0;
}

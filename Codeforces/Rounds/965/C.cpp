#include <bits/stdc++.h>
using namespace std;

int main() {
    uint64_t n, k, m, d;

    cin >> n >> k >> m >> d;

    uint64_t ans = 0;

    for (uint64_t di = 1; di <= d; di++) {
        uint64_t lo = 1, hi = m, mid;
        while (lo <= hi) {
            mid = (hi + lo) / 2LL;

            uint64_t y = n / mid;
            uint64_t z = y / k;
            if (y % k) z++;
            //uint64_t y = n / (mid * k) +
             //   ((bool) (n / mid % k) != 0);

            if (z >= di) {
                lo = mid+1;
                ans = max(ans, mid * di);
            } else {
                hi = mid-1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

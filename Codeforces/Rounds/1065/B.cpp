// Codeforces - Vasya and Isolated Vertices - 1065B Edu Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, m;

    cin >> n >> m;

    int64_t ans_min = n - min(n, m * 2);
    int64_t ans_max = 0;

    int64_t lo = 1, hi = n, mid, v;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        v = mid * (mid-1) / 2;

        if (m <= v) {
            if (mid == 1)
                ans_max = n;
            else
                ans_max = n - mid;

            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    cout << ans_min << " " << ans_max << endl;
    return 0;
}

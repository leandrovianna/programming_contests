// Codeforces - The Lottery - UVA 10325
#include <bits/stdc++.h>
using namespace std;

int64_t lcm(int64_t a, int64_t b) {
    return a * (b / __gcd(a, b));
}

int main() {
    const int M = 15;
    int n, m, a[M];

    while (cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }

        int ans = n;
        for (int mask = 1; mask < (1 << m); mask++) {
            int64_t lcm_acc = 1;
            for (int i = 0; i < m; i++) {
                if ((1 << i) & mask) {
                    lcm_acc = lcm(lcm_acc, a[i]);
                }
            }

            int sz = __builtin_popcount(mask);
            if (sz & 1) {
                ans -= n / lcm_acc;
            } else {
                ans += n / lcm_acc;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

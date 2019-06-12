// Codeforces - Indivisibility - 630K
#include <bits/stdc++.h>
using namespace std;

int64_t lcm(int64_t x, int64_t y) {
    return x * (y / __gcd(x, y));
}

int main() {
    int64_t n;

    const int D = 9;
    const int numbers[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int64_t divcnt[D];

    cin >> n;

    for (int i = 0; i < D; i++) {
        divcnt[i] = n / numbers[i];
    }

    int64_t ans = n;

    for (int mask = 1; mask < (1 << D); mask++) {
        int64_t size = 0, l = 1;
        for (int i = 0; i < D; i++) {
            if (mask & (1 << i)) {
                size += divcnt[i];
                l = lcm(l, numbers[i]);
            }
        }

        size -= n / l;

        if (__builtin_popcount(mask) & 1) {
            ans += size;
        } else {
            ans -= size;
        }
    }

    cout << ans << endl;
    return 0;
}

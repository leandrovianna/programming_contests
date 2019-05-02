//UVA - Coconuts, Revisited - 616
#include <bits/stdc++.h>
using namespace std;

bool solve(int64_t n, int p, int i) {
    if (i == 0)
        return n % p == 0;

    if (n <= 0)
        return false;

    int64_t x = n - 1;
    if (x % p == 0) {
        return solve(x - x / p, p, i-1);
    } else {
        return false;
    }
}

int main() {
    int64_t n;

    while (cin >> n && n >= 0) {
        cout << n << " coconuts, ";

        int64_t ans = 0;
        for (int p = 2; p <= 10000; p++) {
            if (solve(n, p, p)) {
                ans = p;
            }
        }

        if (ans == 0) {
            cout << "no solution\n";
        } else {
            cout << ans << " people and 1 monkey\n";
        }
    }
    return 0;
}

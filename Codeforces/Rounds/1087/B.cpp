// Codeforces - Div Times Mod - 1087B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k;

    cin >> n >> k;

    if (n < k) {
        cout << n + k << endl;
    } else {
        int64_t ans = INT_MAX, y, c;
        for (int64_t i = 1; i < k; i++) {
            if (n % i != 0) continue;
            y = n / i;
            c = (y * k) + i;
            ans = min(c, ans);
        }

        cout << ans << endl;
    }
    return 0;
}

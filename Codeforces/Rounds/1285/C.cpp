// Codeforces - Fadi and LCM - 1285C
#include <bits/stdc++.h>
using namespace std;

const int P = 1000100;
int e[P];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t x;
    cin >> x;

    pair<int64_t, int64_t> ans = {1, x};

    for (int64_t i = 1, j; i * i <= x; i++) {
        if (x % i == 0) {
            j = x / i;

            if (__gcd(i, j) == 1 && max(i, j) < max(ans.first, ans.second)) {
                ans = {i, j};
            }
        }
    }

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}

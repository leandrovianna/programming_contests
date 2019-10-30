#include <bits/stdc++.h>
using namespace std;

int64_t exp(int64_t b, int64_t e, int64_t mod) {
    int64_t ans = 1;
    while (e) {
        if (e & 1) {
            ans = (b * ans) % mod;
        }

        b = (b * b) % mod;
        e >>= 1;
    }

    return ans;
}

const int N = 1000100;
int64_t dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    const int64_t mod = 1000000007;

    cin >> n;

    if (n == 1) {
        cout << "2\n";
        return 0;
    }

    dp[0] = 1;
    dp[1] = 2;
    int64_t inv2 = exp(2, mod - 2, mod);
    for (int64_t i = 2; i <= n; i++) {
        int64_t comb = ((i * (i-1)) % mod * inv2) % mod;
        dp[i] = ((2 * (i * dp[i-1]) % mod) % mod +
                (8 * (comb * dp[i-2]) % mod) % mod) % mod;
    }
    int64_t ans = dp[n];
    
    cout << ans << "\n";
    return 0;
}

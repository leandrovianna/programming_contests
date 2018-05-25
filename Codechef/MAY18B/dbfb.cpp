// Codechef - May Challenge 2018 - Dibs on Fibs - DBFB
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
const int MOD = 1000 * 1000 * 1000 + 7;

int64_t fib[N];
void fibonacci(int n, const int64_t mod = MOD) {
    assert(n < N);
    fib[0] = 1;
    fib[1] = 0;
    fib[2] = 1;
    for (int i = 3; i <= n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, t;
    int64_t x, ans;

    fibonacci(100010);

    cin >> t;

    while (t--) {
        cin >> m >> n;

        ans = 0;
        int64_t fp = 0, sp = 0;

        for (int i = 0; i < m; i++) {
            cin >> x;
            fp = (fp + x) % MOD;
        }

        for (int i = 0; i < m; i++) {
            cin >> x;
            sp = (sp + x) % MOD;
        }

        ans = m * ((sp * fib[n]) % MOD + (fp * fib[n-1]) % MOD) % MOD;
        ans %= MOD;

        cout << ans << "\n";
    }

    return 0;
}

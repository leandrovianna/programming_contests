// Codeforces - Beautiful Numbers - 300C Div2
#include <bits/stdc++.h>
using namespace std;

pair<int, int> extendedEuclids(int a, int b) {
    if (b == 0) {
        return {1, 0};
    } else {
        auto p = extendedEuclids(b, a % b);
        return {p.second,
            p.first - floor((double)a / b) * p.second};
    }
}

int inverseMod(int a, int n) {
    auto p = extendedEuclids(a, n);
    return (p.first % n + n) % n;
}

bool is_good(int x, const int a, const int b) {
    int d;
    while (x > 0) {
        d = x % 10;    
        x /= 10;

        if (d != a && d != b) {
            return false;
        }
    }

    return true;
}

const int N = 1000 * 1000 + 10;
int64_t fac[N];
void factorial(int n, const int mod) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i-1] * i) % mod;
    }
}

int main() {
    const int mod = 1000 * 1000 * 1000 + 7;
    int a, b, n;

    cin >> a >> b >> n;

    factorial(n, mod);

    int64_t ans = 0;
    int qa = n, qb = 0;

    for (int sum = a*n; sum <= b*n; sum = sum - a + b) {
        if (is_good(sum, a, b)) {
            int64_t x = (fac[n] * inverseMod(fac[qa], mod)) % mod;
            x = (x * inverseMod(fac[qb], mod)) % mod;
            ans = (ans + x) % mod;
        }

        qa--;
        qb++;
    }

    cout << ans << endl;

    return 0;
}

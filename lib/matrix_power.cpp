// Codeforces - Gym 101845 - Univ. Nacional de Colombia PC
// Apple Trees
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5;

struct matrix {
    int64_t m[MAXN][MAXN];
};

matrix mult(matrix a, matrix b, int64_t mod) {
    matrix ans;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            ans.m[i][j] = 0;
            for (int k = 0; k < MAXN; k++) {
                ans.m[i][j] += (a.m[i][k] * b.m[k][j]) % mod;
            }
            ans.m[i][j] %= mod;
        }
    }

    return ans;
}

matrix power(matrix base, int64_t exp, int64_t mod) {
    matrix ans;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            ans.m[i][j] = (i == j) ? 1 : 0;
            base.m[i][j] %= mod;
        }
    }

    while (exp) {
        if (exp & 1) {
            ans = mult(ans, base, mod);
        }

        base = mult(base, base, mod);

        exp >>= 1;
    }

    return ans;
}

int main() {
    const int64_t mod = 1000000007;
    int64_t n;

    cin >> n;

    if (n < 10) {
        cout << "1\n";
        return 0;
    }

    matrix a = {{{16, 9, 4, 1, 0},
                 {1, 0, 0, 0, 0},
                 {0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 0, 1, 0} }};

    a = power(a, n/10, mod);

    int64_t ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += a.m[i][0];
        ans %= mod;
    }

    if (n % 10 < 5) {
        ans += a.m[4][0];
        ans %= mod;
    }

    cout << ans << "\n";
    return 0;
}

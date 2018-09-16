// UVA - Contemplation! Algebra - 10655
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2;

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int64_t mod = numeric_limits<int64_t>::max();
    int64_t n, p, q;

    while (cin >> p >> q) {
        if (!(cin >> n)) {
            break;
        }

        if (n == 0) {
            cout << "2\n";
        } else if (n == 1) {
            cout << p << "\n";
        } else {
            matrix ma = {{{p, -q}, {1, 0}}};

            ma = power(ma, n-1, mod);

            int64_t ans = (p * ma.m[0][0] + 2 * ma.m[0][1]) % mod;

            cout << ans << "\n";
        }
    }

    return 0;
}

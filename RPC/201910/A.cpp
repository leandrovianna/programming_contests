#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;

struct matrix {
    int64_t m[MAXN][MAXN];
};

matrix mult(matrix a, matrix b, int64_t mod) {
    matrix ans;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            ans.m[i][j] = 0;
            for (int k = 0; k < MAXN; k++) {
                ans.m[i][j] = (ans.m[i][j] + (a.m[i][k] * b.m[k][j]) % mod) % mod;
            }
        }
    }

    return ans;
}

matrix power(matrix base, int64_t e, int64_t mod) {
    matrix ans;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            ans.m[i][j] = (i == j) ? 1 : 0;
            base.m[i][j] %= mod;
        }
    }

    while (e) {
        if (e & 1) {
            ans = mult(ans, base, mod);
        }

        base = mult(base, base, mod);
        e >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int64_t mod = 1e9 + 7;
    string s;
    char c;
    int k;
    int64_t n;

    while (t--) {
        cin >> s >> k >> n;

        matrix a, b;
        memset(a.m, 0, sizeof(a.m));
        memset(b.m, 0, sizeof(b.m));

        for (const auto &ch : s) {
            b.m[ch - 'a'][ch - 'a']++;
        }

        for (int i = 0; i < MAXN; i++) {
            a.m[i][i] = 1;
        }

        for (int i = 0; i < k; i++) {
            cin >> c >> s;
            a.m[c - 'a'][c - 'a'] = 0;
            for (const auto &ch : s) {
                a.m[c - 'a'][ch - 'a']++;
            }
        }

        a = power(a, n, mod);
        a = mult(b, a, mod);

        int64_t ans = 0;
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                ans = (ans + a.m[i][j]) % mod;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

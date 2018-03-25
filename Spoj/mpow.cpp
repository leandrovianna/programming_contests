//Spoj - Power of Matrix - MPOW
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
typedef struct {
    int64_t mat[N][N];
} matrix;

void mat_print(const matrix &m, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m.mat[i][j];
            if (j < n-1)
                cout << " ";
        }
        cout << endl;
    }
}

matrix mat_mult(const matrix &a, const matrix &b, const int64_t mod) {
    matrix ans;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans.mat[i][j] = 0;
            for (int k = 0; k < N; k++) {
                ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % mod) % mod;
            }
        }
    }

    return ans;
}

matrix mat_pow(const matrix &base, int64_t exp, const int64_t mod) {
    matrix ans, b = base;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans.mat[i][j] = (i == j ? 1 : 0);

    while (exp > 0) {
        if (exp & 1) {
            ans = mat_mult(b, ans, mod);
        }

        b = mat_mult(b, b, mod);
        exp >>= 1;
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);

    const int MOD = 1000000007;
    int t, n, m;
    matrix x;

    cin >> t;

    while (t--) {
        memset(x.mat, 0, sizeof(x.mat));

        cin >> m >> n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                cin >> x.mat[i][j];

        mat_print(mat_pow(x, n, MOD), m);
    }

    return 0;
}

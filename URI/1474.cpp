//URI - Ônibus - 1474
#include <bits/stdc++.h>
using namespace std;

const int M = 2;
typedef struct {
    int64_t mat[M][M];
} matrix;

matrix mult(matrix a, matrix b, int64_t mod) {
    matrix ans;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            a.mat[i][j] %= mod;
            b.mat[i][j] %= mod;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            ans.mat[i][j] = 0;
            for (int k = 0; k < M; k++) {
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod;
            }
            ans.mat[i][j] %= mod;
        }
    }

    return ans;
}

matrix pow(matrix base, int64_t exp, int64_t mod) {
    matrix ans;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            ans.mat[i][j] = (i == j ? 1 : 0);

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

    int64_t n, k, l, i;
    const int mod = 1000000; //10^6

    while (cin >> n >> k >> l) {
        i = n / 5;
        matrix x = {
            { {k, l},
              {1, 0} }
        };

        x = pow(x, i, mod);

        cout << setfill('0') << setw(6) << x.mat[0][0] << endl;
    }
    return 0;
}

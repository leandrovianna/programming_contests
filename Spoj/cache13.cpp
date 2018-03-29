//Spoj - O cachecol da vovó - CACHE13
#include <bits/stdc++.h>
using namespace std;

const int M = 2;
typedef struct {
    int64_t mat[M][M];
} matrix;

int64_t mod(int64_t a, int64_t m) {
    return (a % m + m) % m;
}

matrix mat_mult(const matrix a, const matrix b, const int64_t m) {
    matrix ans;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            ans.mat[i][j] = 0;
            for (int k = 0; k < M; k++) {
                ans.mat[i][j] += mod(a.mat[i][k] * b.mat[k][j], m);
            }
            ans.mat[i][j] = mod(ans.mat[i][j], m);
        }
    }

    return ans;
}

matrix mat_pow(matrix base, int64_t p, const int64_t m) {
    matrix ans;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            base.mat[i][j] = mod(base.mat[i][j], m);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            ans.mat[i][j] = (i == j ? 1 : 0);
        }
    }

    while (p) {
        if (p & 1) {
            ans = mat_mult(base, ans, m);
        }

        base = mat_mult(base, base, m);
        p >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    const int64_t mod = 1000 * 1000 * 1000 + 7;
    matrix m = { { {5, -2}, {1, 0} } };
    matrix b = { { {54, 0}, {12, 0} } };

    int64_t n;
    cin >> n;

    m = mat_pow(m, n-1, mod);
    m = mat_mult(m, b, mod);

    cout << m.mat[1][0] << endl;
    return 0;
}

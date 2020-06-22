#include <bits/stdc++.h>
using namespace std;

const int N = 55;

struct matrix {
    int64_t mat[N][N];
};

matrix mult(matrix a, matrix b, int64_t mod) {
    matrix ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans.mat[i][j] = 0;
            for (int k = 0; k < N; k++) {
                ans.mat[i][j] = 
                    (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % mod) % mod;
            }
        }
    }

    return ans;
}

matrix exp(matrix base, int64_t e, int64_t mod) {
    matrix ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            base.mat[i][j] %= mod;
            if (i == j)
                ans.mat[i][j] = 1;
            else
                ans.mat[i][j] = 0;
        }
    }

    while (e) {
        if (e & 1) ans = mult(base, ans, mod);

        base = mult(base, base, mod);
        e >>= 1;
    }

    return ans;
}

int main() {
    int n, m, k;
    const int64_t mod = 1000000000 + 7;
    matrix mat;

    memset(mat.mat, 0, sizeof(mat.mat));

    cin >> n >> m >> k;

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        mat.mat[a][b] = 1;
    }

    mat = exp(mat, k, mod);

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (mat.mat[i][1] != 0)
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    if (ans.size() > 0) {
        for (size_t i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

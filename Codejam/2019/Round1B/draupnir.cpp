#include <bits/stdc++.h>
using namespace std;

const int N = 7, M = 7; // N variables, M equations
const int INF = 1e9;

pair<int64_t, int64_t> extendedEuclids(int64_t a, int64_t b) {
    if (b == 0) {
        return {1, 0};
    } else {
        auto p = extendedEuclids(b, a % b);
        return {p.second, p.first - (a / b) * p.second};
    }
}

int inverse(int64_t a, int64_t n) {
    auto p = extendedEuclids(a, n);
    return (p.first % n + n) % n;
}

struct Matrix {
    int64_t m[M][N+1];
    int64_t* operator[](size_t i) {
        return m[i];
    };
};

struct Vector {
    int64_t v[N];
    int64_t& operator[](size_t i) {
        return v[i];
    };
};

// n variables, m equations
// note: for reducing error, implicit pivoting can be used
int elimination(Matrix &aug, int n, int m, Vector &ans, int64_t mod) {
    int where[N];
    memset(where, -1, sizeof(where));

    for (int col = 0, row = 0, lgst; col < n && row < m; col++) {
        lgst = row;
        for (int i = row+1; i < m; i++) {
            if (abs(aug.m[i][col]) > abs(aug.m[lgst][col])) {
                lgst = i;
            }
        }

        if (aug.m[lgst][col] == 0) // independent variable or impossible system
            continue;

        swap(aug.m[row], aug.m[lgst]);

        where[col] = row; // assign a row for variable of column col

        // zero elements in column col (except in row)
        for (int i = 0; i < m; i++) {
            if (i == row) continue;

            int64_t c = (aug.m[i][col] * inverse(aug.m[row][col], mod)) % mod;

            for (int j = col; j <= n; j++) {
                // aug.m[i][j] -= aug.m[row][j] * c;
                aug.m[i][j] = ((aug.m[i][j] - (aug.m[row][j] * c) % mod) % mod + mod) % mod;
            }
        }

        row++;
    }

    // assign answer to variables
    memset(ans.v, 0, sizeof(ans.v));
    for (int j = 0; j < n; j++) {
        if (where[j] != -1) {
            ans.v[j] = (aug.m[where[j]][n] * inverse(aug.m[where[j]][j], mod)) % mod;
        }
    }
    
    // verify if system is impossible
    for (int i = 0; i < m; i++) {
        int64_t sum = 0;
        for (int j = 0; j < n; j++) {
            // sum += (ans.v[j] * aug.m[i][j]);
            sum = (sum + (ans.v[j] * aug.m[i][j]) % mod) % mod;
        }

        if (sum != aug.m[i][n]) {
            return 0; // impossible system
        }
    }

    for (int j = 0; j < n; j++) {
        if (where[j] == -1) // infinite solutions
            return INF;
    }

    return 1;
}

const int R = 10;
int64_t ans[R];

int main() {
    const int mod = 1e9 + 7;
    int t, w;

    cin >> t >> w;

    while (t--) {
        Matrix aug;
        Vector b;

        for (int i = 0; i < w; i++) {
            cout << (i+1) << endl;
            cin >> ans[i];
            if (ans[i] == -1)
                return 0;
        }

        int cnt[] = {1, 1, 1, 1, 1, 1};
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if ((i+1) % (j+1) == 0) {
                    cnt[j] *= 2;
                }

                aug[i][j] = cnt[j];
            }
            aug[i][6] = ans[i];
        }

        /*
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j <= 6; j++) {
                cout << aug[i][j] << " ";
            }
            cout << endl;
        }
        */

        elimination(aug, 6, 6, b, mod);
        // cout << elimination(aug, 6, 6, b) << endl;
        for (int i = 0; i < 6; i++) {
            cout << b[i];
            if (i < 5) cout << " ";
        }
        cout << endl;

        int x;
        cin >> x;
        if (x == -1)
            return 0;
    }
    return 0;
}

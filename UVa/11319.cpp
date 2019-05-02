#include <bits/stdc++.h>
using namespace std;

const int N = 7, M = 7; // N variables, M equations
const int INF = 1e9;
const double EPS = 1e-9;

struct Matrix {
    double m[M][N+1];
    double* operator[](size_t i) {
        return m[i];
    };
};

struct Vector {
    double v[N];
    double& operator[](size_t i) {
        return v[i];
    };
};

// n variables, m equations
// note: for reducing error, implicit pivoting can be used
int elimination(Matrix &aug, int n, int m, Vector &ans) {
    int where[N];
    memset(where, -1, sizeof(where));

    for (int col = 0, row = 0, lgst; col < n && row < m; col++) {
        lgst = row;
        for (int i = row+1; i < m; i++) {
            if (fabs(aug.m[i][col]) > fabs(aug.m[lgst][col])) {
                lgst = i;
            }
        }

        if (fabs(aug.m[lgst][col]) < EPS) // independent variable or impossible system
            continue;

        swap(aug.m[row], aug.m[lgst]);

        where[col] = row; // assign a row for variable of column col

        // zero elements in column col (except in row)
        for (int i = 0; i < m; i++) {
            if (i == row) continue;

            double c = aug.m[i][col] / aug.m[row][col];

            for (int j = col; j <= n; j++) {
                aug.m[i][j] -= aug.m[row][j] * c;
            }
        }

        row++;
    }

    // assign answer to variables
    memset(ans.v, 0, sizeof(ans.v));
    for (int j = 0; j < n; j++) {
        if (where[j] != -1) {
            ans.v[j] = aug.m[where[j]][n] / aug.m[where[j]][j];
        }
    }
    
    // verify if system is impossible
    for (int i = 0; i < m; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (ans.v[j] * aug.m[i][j]);
        }

        if (fabs(sum - aug.m[i][n]) > EPS) {
            return 0; // impossible system
        }
    }

    for (int j = 0; j < n; j++) {
        if (where[j] == -1) // infinite solutions
            return INF;
    }

    return 1;
}

int main() {
    int t;
    int n = 7;
    const int Z = 1500;
    uint64_t v, ans2[N], y[Z];

    Matrix aug;
    Vector ans;

    cin >> t;
    while (t--) {
        for (int i = 0; i < n; i++) {
            v = 1;
            for (int j = 0; j < n; j++) {
                aug[i][j] = v;
                v *= (i+1);
            }
        }

        for (int i = 0; i < Z; i++) {
            cin >> y[i];
        }

        for (int i = 0; i < n; i++) {
            aug[i][n] = y[i];
        }

        bool has_solution = true;

        if (elimination(aug, n, n, ans) != 1) {
            has_solution = false;
        } else {
            for (int j = 0; j < n; j++) {
                if (ans[j] < -EPS) {
                    // it is negative
                    has_solution = false;
                    break;
                }

                ans2[j] = static_cast<uint64_t>(ans[j] + EPS);

                if (ans2[j] > 1000) {
                    // greater than 1000
                    has_solution = false;
                    break;
                }
            }

            // verify if ans2 vector generate the results of function of input
            for (int i = 0; i < 1500; i++) {
                uint64_t f = 0;
                v = 1;
                for (int j = 0; j < n; j++) {
                    f += ans2[j] * v;
                    v *= (i+1);
                }

                if (f != y[i]) {
                    has_solution = false;
                    break;
                }
            }
        }

        if (has_solution) {
            for (int j = 0; j < n; j++) {
                cout << ans2[j] << " \n"[j == n-1];
            }
        } else {
            cout << "This is a smart sequence!" << endl;
        }
    }
    return 0;
}

// Codeforces Gym - Black Vienna - SWERC 15
#include <bits/stdc++.h>
using namespace std;

const int N = 55, M = 160; // N variables, M equations
const int INF = 1e9;

struct Matrix {
    bitset<N+1> m[M];
    bitset<N+1>& operator[](size_t i) {
        return m[i];
    };
};

struct Vector {
    bitset<N> v;
    int operator[](size_t i) {
        return v[i];
    };
};

// n variables, m equations
int elimination(Matrix &aug, int n, int m, Vector &ans) {
    int where[N];
    memset(where, -1, sizeof(where));

    for (int col = 0, row = 0; col < n && row < m; col++) {
        for (int i = row; i < m; i++) {
            if (aug.m[i][col]) {
                swap(aug.m[i], aug.m[row]);
                break;
            }
        }

        if (!aug.m[row][col]) // independent variable or impossible system
            continue;

        where[col] = row; // assign a row for variable of column col

        // zero elements in column col (except in row)
        for (int i = 0; i < m; i++) {
            if (i != row && aug.m[i][col]) {
                aug.m[i] ^= aug.m[row];
            }
        }

        row++;
    }

    // assign answer to variables
    for (int j = 0; j < n; j++) {
        if (where[j] != -1) {
            ans.v[j] = aug.m[where[j]][n];
        }
    }
    
    // verify if system is impossible
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (where[j] != -1)
                sum ^= (ans.v[j] & aug.m[i][j]);
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

vector<char> comb;
vector<vector<char>> combs;

void gen_comb(int i, int d) {
    if (d == 3) {
        combs.push_back(comb);
        return;
    }

    if (i == 26)
        return;

    gen_comb(i+1, d);
    comb.push_back('A' + i);
    gen_comb(i+1, d+1);
    comb.pop_back();
}

int solve(Matrix a, int v1, int v2, int v3, int n, int m) {
    int k = 0;
    for (int i = 0; i < 26; i++) {
        if (i == v1 || i == v2 || i == v3) {
            // not A1
            // not A2
            a[m+k][i] = 1;
            a[m+k][n] = 0;
            k++;
            a[m+k][26 + i] = 1;
            a[m+k][n] = 0;
            k++;
        } else {
            // A1 xor A2
            a[m+k][i] = 1;
            a[m+k][26 + i] = 1;
            a[m+k][n] = 1;
            k++;
        }
    }

    Vector ans;
    return elimination(a, n, m+k, ans);
}

int main() {
    int n, p, q, e;
    char var1, var2;

    Matrix a;

    cin >> e;

    int j = 0;
    n = 52;
    for (int i = 0; i < e; i++) {
        cin >> var1 >> var2 >> p >> q;
        int v1 = (p == 2 ? 26 : 0) + (var1 - 'A');
        int v2 = (p == 2 ? 26 : 0) + (var2 - 'A');

        switch (q) {
            case 0:
                // not A1 and not B1
                a[j][v1] = 1;
                a[j][n] = 0;
                j++;
                a[j][v2] = 1;
                a[j][n] = 0;
                j++;
                break;
            case 1:
                // A1 xor B2
                a[j][v1] = 1;
                a[j][v2] = 1;
                a[j][n] = 1;
                j++;
                break;
            case 2:
                // A1 and B1
                a[j][v1] = 1;
                a[j][n] = 1;
                j++;
                a[j][v2] = 1;
                a[j][n] = 1;
                j++;
                break;
        }
    }


    gen_comb(0, 0);

    int count_answer = 0;

    for (const auto &c : combs) {
        int v1 = c[0] - 'A',
            v2 = c[1] - 'A',
            v3 = c[2] - 'A';

        int num_sol = solve(a, v1, v2, v3, n, j);
        if (num_sol > 0) {
            count_answer++;
        }
    }

    cout << count_answer << "\n";
    return 0;
}

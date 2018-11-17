// TAP 2018/2 - Modificando SAT - M4
#include <bits/stdc++.h>
using namespace std;

const int N = 2000, M = 2000; // N variables, M equations
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
    for (int j = n-1; j >= 0; j--) {
        if (where[j] != -1) {
            ans.v[j] = aug.m[where[j]][n];
        } else {
            ans.v[j] = 1; // true for free variables
            // back substitution where variable j appear (flip answer of line)
            for (int i = 0; i < m; i++) {
                if (aug.m[i][j]) {
                    aug.m[i].flip(n);
                }
            }
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
int main() {
    int m, n;
    string line, w;
    bool neg;

    cin >> m >> n;

    Matrix aug;
    memset(aug.m, 0, sizeof(aug.m));
    Vector ans;

    for (int i = 0; i < m; i++) {
        cin.ignore();
        getline(cin, line);
        line.erase(remove(line.begin(), line.end(), '('), line.end());
        line.erase(remove(line.begin(), line.end(), ')'), line.end());

        istringstream iss(line);

        neg = false;
        int count_neg = 0;

        while (iss >> w) {
            if (w == "not") {
                neg = true;
            } else if (w != "and" && w != "or") {
                w = w.substr(1); // remove x from x999
                int idx = stoi(w);
                // inverse order of variables
                aug[i].flip(n-idx); // flip for each variable

                if (neg)
                    count_neg++;
                neg = false;
            }
        }

        aug[i][n] = !(count_neg & 1);
    }

    int sol = elimination(aug, n, m, ans);

    if (sol == 0) {
        cout << "impossible" << endl;
        return 0;
    }

    for (int j = n-1; j >= 0; j--) {
        cout << (ans[j] ? "T" : "F");
    }
    cout << endl;
    return 0;
}

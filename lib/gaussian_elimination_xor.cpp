// Lib - Gaussian Elimination XOR
// For linear equation systems in modulo 2
#include <bits/stdc++.h>
using namespace std;

const int N = 10, M = 10; // N variables, M equations
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
            cout << aug.m[i] << endl;
            return 0; // impossible system
        }
    }

    for (int j = 0; j < n; j++) {
        if (where[j] == -1) // infinite solutions
            return INF;
    }

    return 1;
}

void printSol(Matrix aug, int n, int m) {
    // print system
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << aug.m[i][j];
        }
        cout << endl;
    }

    Vector ans;
    cout << "number of solutions: " << elimination(aug, n, m, ans) << endl;
    cout << "solution (x0, ..., x" << n-1 << "): ";
    for (int j = 0; j < n; j++) {
        cout << ans[j] << " ";
    }
    cout << endl;
}

int main() {
    Matrix aug;
    // inverse order of values of matrix (bitset details)
    aug.m[0] = bitset<N+1>("11101");
    aug.m[1] = bitset<N+1>("01110");
    aug.m[2] = bitset<N+1>("01011");
    aug.m[3] = bitset<N+1>("10111");

    cout << "System 1: " << endl;
    printSol(aug, 4, 4);

    aug.m[0] = bitset<N+1>("1111");
    aug.m[1] = bitset<N+1>("0001");
    aug.m[2] = bitset<N+1>("0111");
    aug.m[3] = bitset<N+1>("0110");

    cout << "System 2: " << endl;
    printSol(aug, 3, 4);

    aug.m[0] = bitset<N+1>("0000001");
    aug.m[1] = bitset<N+1>("1001011");
    aug.m[2] = bitset<N+1>("1010101");
    aug.m[3] = bitset<N+1>("0010110");
    aug.m[4] = bitset<N+1>("0001110");

    cout << "System 3: " << endl;
    printSol(aug, 6, 5);
    
	return 0;
}

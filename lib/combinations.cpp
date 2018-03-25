//Combination Algorithm
#include <bits/stdc++.h>
using namespace std;

const int N = 120;
int comb[N][N];
int combination(int n, int m) {
    return comb[n][m];
}

void pre_compute(int n) {
    assert(n < N-1);
    for (int i = 0; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 0; j < i; j++) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    return 0;
}


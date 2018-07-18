// Codeforces - Xor-paths - 1006F Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, m;
int64_t k;
int64_t a[N][N];
map<int64_t, int> xorv[N][N];
int64_t answer = 0;

void backtrack1(int i, int j, int step, int64_t xorsum) {
    if (step == n) {
        xorv[i][j][a[i][j] ^ xorsum]++;
    } else {

        if (i < n-1)
            backtrack1(i+1, j, step+1, xorsum ^ a[i][j]);

        if (j < m-1)
            backtrack1(i, j+1, step+1, xorsum ^ a[i][j]);
    }
}

void backtrack2(int i, int j, int step, int64_t xorsum) {
    if (step == m) {
        // queremos caminhos com xorsum = k
        // seja x e y o xorsum dos dois caminhos
        // x ^ y = k
        // x ^ y ^ y = k ^ y
        // x ^ 0 = k ^ y
        // x = k ^ y
        // entao chegando aqui basta contar quantos
        // caminhos sao k ^ y, ja que guardamos os com
        // valores x em backtrack1
        
        answer += xorv[i][j][k ^ xorsum];
    } else {

        if (i > 0)
            backtrack2(i-1, j, step+1, xorsum ^ a[i][j]);

        if (j > 0)
            backtrack2(i, j-1, step+1, xorsum ^ a[i][j]);
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    backtrack1(0, 0, 1, 0);
    backtrack2(n-1, m-1, 1, 0);

    cout << answer << endl;

    return 0;
}

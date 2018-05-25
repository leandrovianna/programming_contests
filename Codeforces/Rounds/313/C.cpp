// Codeforces - Ilya and Matrix - 313C Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1000;
int64_t mat[N][N];

int main() {
    ios::sync_with_stdio(false);
    int n, m;

    cin >> n;
    m = sqrt(n);

    vector<int64_t> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<>());

    for (int i = 0, k = 0; i < n && k < m/2; i += 4, k++) {
        mat[k][k] = v[i];
        mat[m-1-k][m-1-k] = v[i+1];
    }

    for (int i = 2, k = 0; i < n && k < m/2; i += 4, k++) {
        mat[k][m-1-k] = v[i];
        mat[m-1-k][k] = v[i+1];
    }

    for (int i = 0, k = 2*m; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j || i+j == m-1)
                continue;
            mat[i][j] = v[k];
            k++;
        }
    }

    int64_t ans = 0;
    for (int j = 1; j <= n; j *= 4) {
        for (int i = 0; i < j; i++) {
            ans += v[i];
        }
    }

    cout << ans << endl;

    return 0;
}

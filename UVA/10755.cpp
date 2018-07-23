// UVA - Garbage Heap - 10755
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, t;
    const int N = 20;
    int64_t mat[N][N][N];

    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < c; k++) {
                    int64_t &value = mat[i][j][k];
                    cin >> value;

                    if (i > 0)
                        value += mat[i-1][j][k];

                    if (j > 0)
                        value += mat[i][j-1][k];

                    if (i > 0 && j > 0)
                        value -= mat[i-1][j-1][k];
                }
            }
        }

        int64_t ans = LLONG_MIN;

        for (int i0 = 0; i0 < a; i0++) {
            for (int i1 = i0; i1 < a; i1++) {
                for (int j0 = 0; j0 < b; j0++) {
                    for (int j1 = j0; j1 < b; j1++) {
                        int64_t v = 0, x;

                        for (int k = 0; k < c; k++) {
                            x = mat[i1][j1][k];

                            if (i0 > 0)
                                x -= mat[i0-1][j1][k];

                            if (j0 > 0)
                                x -= mat[i1][j0-1][k];

                            if (i0 > 0 && j0 > 0)
                                x += mat[i0-1][j0-1][k];

                            v += x; 
                            ans = max(ans, v);
                            if (v < 0)
                                v = 0;
                        }
                    }
                }
            }
        }

        cout << ans << "\n";
        if (t > 0) cout << "\n";
    }
    return 0;
}

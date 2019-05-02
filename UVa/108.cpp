// UVA - Maximum Sum - 108
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n;
    int a[N][N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];

            if (i > 0)
                a[i][j] += a[i-1][j];

            if (j > 0)
                a[i][j] += a[i][j-1];

            if (i > 0 && j > 0)
                a[i][j] -= a[i-1][j-1];
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = i; x < n; x++) {
                for (int y = j; y < n; y++) {
                    int v = a[x][y];

                    if (i > 0)
                        v -= a[i-1][y];

                    if (j > 0)
                        v -= a[x][j-1];

                    if (i > 0 && j > 0)
                        v += a[i-1][j-1];

                    ans = max(ans, v);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

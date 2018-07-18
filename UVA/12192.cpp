// UVA - Grapevine - 12192
#include <bits/stdc++.h>
using namespace std;

const int N = 550;

int main() {
    int n, m, q;
    int a[N][N];

    while (cin >> n >> m, n || m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        cin >> q;

        for (int qi = 0, l, u; qi < q; qi++) {
            cin >> l >> u;

            int ans = 0;
            for (int line = 0; line < n; line++) {
                auto it = lower_bound(a[line], a[line]+m, l);
                int idx = it - a[line];
                for (int k = ans; k < n; k++) {
                    if (line + k >= n || idx + k >= m || a[line + k][idx + k] > u)
                        break;

                    ans = k + 1;
                }
            }

            cout << ans << "\n";
        }

        cout << "-" << endl;
    }
    return 0;
}

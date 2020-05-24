#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int mat[N][N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        int trace = 0, rows = 0, columns = 0;

        for (int i = 0; i < n; i++) {
            trace += mat[i][i];
        }

        for (int i = 0; i < n; i++) {
            memset(cnt, 0, sizeof(cnt));
            for (int j = 0; j < n; j++) {
                cnt[mat[i][j]]++;
            }

            for (int v = 1; v <= n; v++) {
                if (cnt[v] > 1) {
                    rows++;
                    break;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; i++) {
                cnt[mat[i][j]]++;
            }

            for (int v = 1; v <= n; v++) {
                if (cnt[v] > 1) {
                    columns++;
                    break;
                }
            }
        }

        cout << "Case #" << ti << ": "
            << trace << " "
            << rows << " "
            << columns << "\n";
    }
    return 0;
}

// Codeforces - Mysterious Crime - 1043D
#include <bits/stdc++.h>
using namespace std;

const int N = 100100, M = 10;
int a[M][N];
int p[M];
int pre[M][N];
bool proc[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][a[i][j]] = j;
        }
    }

    int64_t ans = 0;
    for (int k = 0, v; k < n; k++) {
        v = a[0][k];

        if (proc[v])
            continue;

        for (int i = 0; i < m; i++) {
            p[i] = pre[i][v];
        }

        int64_t len = 0;
        bool finish = false;
        while (!finish) {
            proc[a[0][p[0]]] = true;
            len++;

            if (p[0] < n-1) {
                p[0]++;
            } else {
                break;
            }

            for (int i = 1; i < m; i++) {
                if (p[i] < n-1) {
                    p[i]++;
                    if (a[i][p[i]] != a[i-1][p[i-1]]) {
                        finish = true;
                        break;
                    }
                } else {
                    finish = true;
                    break;
                }
            }
        }

        ans += len * (len+1) / 2;
    }

    cout << ans << endl;
    return 0;
}

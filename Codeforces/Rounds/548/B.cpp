// Codeforces - Mike and Fun - 548B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 510;
    int n, m, q, x, y;
    int grid[N][N];
    int best[N];

    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        best[i] = 0;

        int local_mx = 0, count = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1)
                count++;
            else 
                local_mx = max(local_mx, count), count = 0;
        }

        local_mx = max(local_mx, count);
        best[i] = local_mx;
    }

    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        x--;
        y--;
        grid[x][y] = !grid[x][y];

        int local_mx = 0, count = 0;
        for (int j = 0; j < m; j++) {
            if (grid[x][j] == 1)
                count++;
            else
                local_mx = max(local_mx, count), count = 0;

        }
        local_mx = max(local_mx, count);
        best[x] = local_mx;

        int mx = 0;
        for (int k = 0; k < n; k++) {
            mx = max(mx, best[k]);
        }

        cout << mx << "\n";
    }

    return 0;
}

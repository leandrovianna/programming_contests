// Lib - Floyd Warshall
#include <bits/stdc++.h>
using namespace std;

const int N = 110, inf = 1e9;
int64_t dist[N][N];

void floyd_warshall(int n) {
    for (int v = 1; v <= n; v++) {
        for (int u = 1; u <= n; u++) {
            for (int q = 1; q <= n; q++) {
                dist[u][q] = min(dist[u][q], dist[u][v] + dist[v][q]);
            }
        }
    }
}

int main() {
    int t, n, m;

    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int v = 1; v <= n; v++) {
            for (int u = 1; u <= n; u++) {
                if (u == v)
                    dist[v][u] = 0;
                else
                    dist[v][u] = inf;
            }
        }

        int64_t d;
        for (int i = 0, x, y; i < m; i++) {
            cin >> x >> y >> d;
            dist[x][y] = min(dist[x][y], d);
            dist[y][x] = min(dist[y][x], d);
        }

        floyd_warshall(n);

        for (int v = 1; v <= n; v++) {
            for (int u = 1; u <= n; u++) {
                cout << dist[v][u] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

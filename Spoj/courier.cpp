// Spoj - The Courier - COURIER
#include <bits/stdc++.h>
using namespace std;

int b, k;

const int64_t inf = 1e15;
const int N = 110, M = 15;
int64_t dist[N][N];
pair<int, int> req[N];

int64_t dp[N][1 << M];
int used[N][1 << M], vis = 1;

int64_t solve(int i, int mask) {
    if (mask == (1 << k)-1) {
        return dist[i][b];
    }

    int64_t &ans = dp[i][mask];
    if (used[i][mask] == vis)
        return ans;

    ans = inf;

    for (int j = 0, x, y; j < k; j++) {
    	x = req[j].first; 
        y = req[j].second;

        if (dist[i][x] != inf && dist[x][y] != inf) {
        	if((mask & (1 << j)) == 0){
	            ans = min(ans, 
	                    dist[i][x] + dist[x][y] + solve(y, mask | (1 << j)));
        	}
        }
    }

    used[i][mask] = vis;
    return ans;
}

int main() {
    int t, n, m, z;

    cin >> t;

    while (t--) {
        cin >> n >> m >> b;

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

        cin >> z;
        k = 0;
        for (int i = 0, x, y, bj; i < z; i++) {
            cin >> x >> y >> bj;
            for (int j = 0; j < bj; j++) {
                req[k] = {x, y};
                k++;
            }
        }

        for (int v = 1; v <= n; v++) {
            for (int u = 1; u <= n; u++) {
                for (int q = 1; q <= n; q++) {
                    dist[u][q] = min(dist[u][q], dist[u][v] + dist[v][q]);
                }
            }
        }

        vis++;
        cout << solve(b, 0) << "\n";
    }
    return 0;
}

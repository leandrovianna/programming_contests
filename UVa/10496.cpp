// UVA - 10496 - Collecting Beepers
#include <bits/stdc++.h>
using namespace std;

const int N = 22, INF = 1000000000;
const int M = 15, V = 1 << M;
int dp[M][V], used[M][V], vis = 0;
int dist[M][M];
int m;

int solve(int pos, int visited) {
    int &ans = dp[pos][visited];

    if (used[pos][visited] == vis)
        return ans;

    used[pos][visited] = vis;

    if (visited == (1 << (m+1))-1) {
        return ans = dist[pos][0];
    }

    ans = INF;

    for (int v = 0; v <= m; v++) {
        if (v != pos && (visited & (1 << v)) == 0) {
            ans = min(ans, dist[pos][v] + solve(v, visited | (1 << v)));
        }
    }

    return ans;
}

int main() {
    pair<int, int> coord[M];
    int t, x, y;

    cin >> t;

    while (t--) {
        cin >> x >> y;
        cin >> coord[0].first >> coord[0].second;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> coord[i].first >> coord[i].second;
        }
        for (int v = 0; v <= m; v++) {
            for (int u = 0; u <= m; u++) {
                dist[v][u] = abs(coord[u].first - coord[v].first)
                    + abs(coord[u].second - coord[v].second);
            }
        }
        vis++;
        cout << "The shortest path has length "
            << solve(0, 1) << "\n";
    }
    return 0;
}

// Spoj - BITMAP
#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int I[] = {+0, -1, +0, +1};
const int J[] = {-1, +0, +1, +0};
int grid[N][N], vis[N][N], ans[N][N], testid;

void bfs(int n, int m) {
    queue<pair<pair<int, int>, pair<int, int>>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) {
                q.push({{i, j}, {i, j}});
            }
        }
    }

    while (!q.empty()) {
        auto t = q.front().first;
        auto s = q.front().second;
        q.pop();

        if (vis[t.first][t.second] == testid)
            continue;
        vis[t.first][t.second] = testid;

        ans[t.first][t.second] = abs(s.first - t.first) + abs(s.second - t.second);

        for (int k = 0; k < 4; k++) {
            int di = t.first + I[k];
            int dj = t.second + J[k];

            if (0 <= di && di < n && 0 <= dj && dj < m) {
                q.push({{di, dj}, s});
            }
        }
    }
}

int main() {
    int t, n, m;

    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                grid[i][j] = ch - '0';
            }
        }


        testid++;
        bfs(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j];
                if (j < m-1) cout << " ";
                else cout << "\n";
            }
        }
    }
    return 0;
}

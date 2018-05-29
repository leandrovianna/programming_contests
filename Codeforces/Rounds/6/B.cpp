// Codeforces - President's Office - 6B Div2
#include <bits/stdc++.h>
using namespace std;

const int I[] = {+0, -1, +0, +1};
const int J[] = {-1, +0, +1, +0};

int main() {
    const int N = 110;
    int n, m;
    char pres, grid[N][N];
    
    cin >> n >> m >> pres;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bool neigh[N];
    for (int i = 0; i < N; i++)
        neigh[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == pres) {
                for (int k = 0; k < 4; k++) {
                    int di = i + I[k];
                    int dj = j + J[k];
                    if (0 <= di && di < n && 0 <= dj
                            && dj < m &&  grid[di][dj] != '.') {
                        neigh[grid[di][dj]-'A'] = true;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == pres - 'A')
            continue;
        if (neigh[i])
            ans++;
    }

    cout << ans << endl;
    return 0;
}

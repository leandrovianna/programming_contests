#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int I[] = {-1, -1, -1, +0, +0, +1, +1, +1};
const int J[] = {-1, +0, +1, -1, +1, -1, +0, +1};

char grid[N][N];

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bool yes = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*')
                continue;

            int h = 0;
            for (int k = 0; k < 8; k++) {
                int di = I[k] + i;
                int dj = J[k] + j;
                if (0 <= di && di < n && 0 <= dj && dj < m
                        && grid[di][dj] == '*') {
                    h++;
                }
            }

            int l = (grid[i][j] == '.' ? 0 : grid[i][j] - '0');
            if (l != h) {
                yes = false;
                break;
            }
        }

        if (!yes) {
            break;
        }
    }

    cout << (yes ? "YES" : "NO") << endl;

    return 0;
}

// Codeforces - Golden Plate - 1072A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h, k;
    const int N = 110;
    bool grid[N][N];

    cin >> w >> h >> k;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            grid[i][j] = false;
        }
    }

    for (int x = 0; x < k; x++) {
        for (int i = x*2; i < h-x*2; i++) {
            grid[i][x*2] = grid[i][w-x*2-1] = true;
        }

        for (int j = x*2; j < w-x*2; j++) {
            grid[x*2][j] = grid[h-x*2-1][j] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j])
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

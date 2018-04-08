//Codejam - Go, Gopher! - 2018 Qualification
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
    const int E = 1000;
    int t, a, y, i, j;
    const int X = 10;
    const int LY = 1, RY = 67;

    cin >> t;
    while (t--) {
        cin >> a;

        bool ok = false;

        set<ii> cells;
        for (int i = X-1; i <= X+1; i++)
            for (int j = LY; j <= RY; j++)
                cells.insert({i, j});

        for (int e = 0; e < E; e++) {
            y = cells.begin()->second;
            if (y == LY) y++;
            else if (y == RY) y--;

            cout << X << " " << y << endl;

            cin >> i >> j;

            if (i == -1 && j == -1) {
                return 0;
            } else if (i == 0 && j == 0) {
                ok = true;
                break;
            }

            // remove celula preenchida
            cells.erase({i, j});
        }

        if (!ok) {
            cin >> i >> j;
            if (i == -1 && j == -1) {
                return 0;
            }
        }
    }
    
    return 0;
}

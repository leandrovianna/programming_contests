// Codeforces - Diverse Matrix
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << "0\n";
        return 0;
    }

    a[0][0] = 2;

    if (r < c) {
        for (int i = 1, j = 4; i < r; i++, j += 2) {
            a[i][0] = j;
        }

        for (int i = 1, j = 3; i < c; i++) {
            a[0][i] = j;
            j++;
            if (j % 2 == 0 && j <= a[r-1][0])
                j++;
        }
    } else {
        for (int i = 1, j = 4; i < c; i++, j += 2) {
            a[0][i] = j;
        }

        for (int i = 1, j = 3; i < r; i++) {
            a[i][0] = j;
            j++;
            if (j % 2 == 0 && j <= a[0][c-1])
                j++;
        }
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            a[i][j] = a[0][j] * a[i][0];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

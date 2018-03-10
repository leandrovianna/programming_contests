//Codeforces - Protect Sheep - 948A Div2
#include <bits/stdc++.h>
using namespace std;

const int L = 550;
const int I[] = {+0, -1, +0, +1};
const int J[] = {+1, +0, -1, +0};
char grid[L][L];

int main() {
    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    bool impos = false;
    int di, dj;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'S') {
                for (int k = 0; k < 4; k++) {
                    di = i + I[k];
                    dj = j + J[k];
                    if (0 <= di && di < r && 0 <= dj && dj < c) {
                        if (grid[di][dj] == 'W') {
                            impos = true;
                        }
                    }
                }
            }
        }
    }

    if (impos) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '.')
                    cout << "D";
                else
                    cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}

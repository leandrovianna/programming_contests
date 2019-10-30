#include <bits/stdc++.h>
using namespace std;

const int N = 20;
char grid[N][N];
int cnt, r, c;
const char nextCh = 'B';

bool okHor(int i, int j) {
    for (int k = j+1; k < c; k++) {
        if (grid[i][k] == nextCh)
            break;
        if (grid[i][k] == '#')
            return false;
    }
    for (int k = j-1; k >= 0; k--) {
        if (grid[i][k] == nextCh)
            break;
        if (grid[i][k] == '#')
            return false;
    }

    return true;
}

bool okVer(int i, int j) {
    for (int k = i+1; k < r; k++) {
        if (grid[k][j] == nextCh)
            break;
        if (grid[k][j] == '#')
            return false;
    }
    for (int k = i-1; k >= 0; k--) {
        if (grid[k][j] == nextCh)
            break;
        if (grid[k][j] == '#')
            return false;
    }

    return true;
}

bool backtrack(int moves) {
    bool withouMoves = true;
    bool win = false;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '.') {
                if (okHor(i, j)) {
                    withouMoves = false;

                    int beg = -1, en = c;
                    for (int k = j; k < c; k++) {
                        if (grid[i][k] == nextCh) {
                            en = k;
                            break;
                        }
                        grid[i][k] = nextCh;
                    }
                    for (int k = j-1; k >= 0; k--) {
                        if (grid[i][k] == nextCh) {
                            beg = k;
                            break;
                        }
                        grid[i][k] = nextCh;
                    }

                    bool res = backtrack(moves+1);

                    for (int k = beg+1; k < en; k++) {
                        grid[i][k] = '.';
                    }

                    win |= res;

                    if (res && moves == 0)
                        cnt++;
                }
                
                if (okVer(i, j)) {
                    withouMoves = false;

                    int beg = -1, en = r;
                    for (int k = i; k < r; k++) {
                        if (grid[k][j] == nextCh) {
                            en = k;
                            break;
                        }
                        grid[k][j] = nextCh;
                    }
                    for (int k = i-1; k >= 0; k--) {
                        if (grid[k][j] == nextCh) {
                            beg = k;
                            break;
                        }
                        grid[k][j] = nextCh;
                    }

                    bool res = backtrack(moves+1);

                    for (int k = beg+1; k < en; k++) {
                        grid[k][j] = '.';
                    }

                    win |= res;

                    if (res && moves == 0)
                        cnt++;
                }
            }
        }
    }

    if (withouMoves) {
        /*
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
        */
        if (moves & 1) {
            return true;
        } else {
            return false;
        }
    }

    return win;
}

int main() {
    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }

        cnt = 0;
        backtrack(0);

        cout << "Case #" << ti << ": " << cnt << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 110;

char grid[N][N];
int score[N][N];

int main() {
    ios::sync_with_stdio(false);
    int n, k;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    bool ship;
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n-k+1; l++) {
            ship = true;
            for (int r = l; r < l+k; r++) {
                if (grid[i][r] == '#') {
                    ship = false;
                    break;
                }
            }

            if (ship) {
                for (int r = l; r < l+k; r++) {
                    score[i][r]++;
                    maxi = max(maxi, score[i][r]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n-k+1; l++) {
            ship = true;
            for (int r = l; r < l+k; r++) {
                if (grid[r][i] == '#') {
                    ship = false;
                    break;
                }
            }

            if (ship) {
                for (int r = l; r < l+k; r++) {
                    score[r][i]++;
                    maxi = max(maxi, score[r][i]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (score[i][j] == maxi) {
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
    return 0;
}

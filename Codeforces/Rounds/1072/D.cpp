// Codeforces - Minimum path - 1072D Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 2010, inf = 1e9;
char grid[N][N];
bool mark[N][N];

int dp[N][N];

int main() {
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = grid[0][0] != 'a' ? 1 : 0;
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + (grid[0][j] != 'a' ? 1 : 0);
        dp[j][0] = dp[j-1][0] + (grid[j][0] != 'a' ? 1 : 0);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (grid[i][j] != 'a' ? 1 : 0);
        }
    }

    int qtdA = 0;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] <= k) {
                if (i + j + 1 >= qtdA) {
                    if (i + j + 1 > qtdA) {
                        pos.clear();
                    }

                    qtdA = i + j + 1;
                    pos.push_back({i, j});
                }
            }
        }
    }

    for (const auto &p : pos) {
        mark[p.first][p.second] = true;
    }

    string answer = string(qtdA, 'a');

    if (qtdA == 0) {
        answer += grid[0][0];
        qtdA = 1;
        mark[0][0] = true;
    }

    for (int x = qtdA; x < 2*n-1; x++) {
        int i = max(0, x-n+1);
        int j = min(x, n-1);

        pos.clear();
        char mi = 'z';
        while (j >= 0 && i < n) {
            if ((i > 0 && mark[i-1][j]) || (j > 0 && mark[i][j-1])) {
                if (grid[i][j] == mi) {
                    pos.push_back({i, j});
                } else if (grid[i][j] < mi) {
                    mi = grid[i][j];
                    pos.clear();
                    pos.push_back({i, j});
                }
            }

            i++;
            j--;
        }

        for (const auto &p : pos) {
            mark[p.first][p.second] = true;
        }

        answer += mi;
    }

    cout << answer << "\n";

    return 0;
}

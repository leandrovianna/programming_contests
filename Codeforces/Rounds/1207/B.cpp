// Codeforces - 1207B - Square Filling
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int a[N][N], b[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }

    vector<pair<int, int>> answer;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            if (a[i][j] == 1 && a[i][j+1] == 1 && a[i+1][j] == 1 && a[i+1][j+1] == 1) {
                answer.push_back({i+1, j+1});
                b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
            }
        }
    }

    bool impossible = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                impossible = true;
                break;
            }
        }
    }

    if (impossible) {
        cout << "-1\n";
    } else {
        cout << answer.size() << "\n";
        for (const auto &p : answer) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
char q1[N][N], q2[N][N];

int main() {
    int l, c;

    cin >> l >> c;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> q1[i][j];
        }
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> q2[i][j];
        }
    }

    vector<pair<int, int>> diff;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (q1[i][j] != q2[i][j]) {
                diff.push_back({i+1, j+1});
            }
        }
    }

    sort(diff.begin(), diff.end());

    for (const auto &p : diff) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

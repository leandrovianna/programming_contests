// Codeforces - Bear and Three Musketeers - 574B Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 4010;
vector<int> v[N]; // neighborhood
bool s[N][N]; // true, if i knows j

int main() {
    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> peers;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;

        peers.push_back({x, y});
        v[x].push_back(y);
        v[y].push_back(x);
        s[x][y] = s[y][x] = true;
    }

    int answer = INT_MAX;

    for (const auto &p : peers) {
        int i = p.first, j = p.second;
        for (int k = 0; k < n; k++) {
            if (s[i][k] && s[j][k]) {
                answer = min(answer, (int) v[i].size() + (int) v[j].size() - 2 * s[i][j]
                        + (int) v[k].size() - 2 * s[k][i] - 2 * s[k][j]);
            }
        }
    }

    if (answer == INT_MAX) {
        answer = -1;
    }

    cout << answer << "\n";
    return 0;
}

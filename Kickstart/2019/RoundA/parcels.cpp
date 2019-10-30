#include <bits/stdc++.h>
using namespace std;

const int N = 300;
int grid[N][N], dist[N][N];

pair<int, int> new_offices[N+N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, r, c;

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> r >> c;

        vector<pair<int, int>> offices;

        char ch;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> ch;
                grid[i][j] = ch - '0';

                if (grid[i][j]) {
                    offices.push_back({i, j});
                }
            }
        }

        for (int d = 0; d < N+N; d++) {
            new_offices[d] = {-1, 0};
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) continue;

                dist[i][j] = 1e9;
                for (const auto &off : offices) {
                    dist[i][j] = min(dist[i][j],
                            abs(off.first - i) + abs(off.second - j));
                }

                new_offices[dist[i][j]] = {i, j};
            }
        }

        int answer = 1e9;

        if ((int) offices.size() == r * c) {
            answer = 0;
        }

        for (int k = 0; k < N+N; k++) {
            if (new_offices[k].first == -1) continue;

            int largest_dist = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j]) continue;

                    // new office
                    int d = min(dist[i][j], 
                            abs(new_offices[k].first - i) + abs(new_offices[k].second - j));

                    if (d > largest_dist) {
                        largest_dist = d;
                    }
                }
            }

            answer = min(answer, largest_dist);
        }

        cout << "Case #" << ti << ": " << answer << "\n";
    }
    return 0;
}

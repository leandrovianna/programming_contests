// Codeforces - New Year and the Treasure Geolocation - 1091B
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
pair<int, int> obl[N];
vector<pair<int, int>> points;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> obl[i].first >> obl[i].second;
    }

    for (int i = 0, x, y, nx, ny; i < n; i++) {
        cin >> x >> y;

        for (int j = 0; j < n; j++) {
            nx = obl[j].first + x;
            ny = obl[j].second + y;
            
            points.push_back({nx, ny});
        }
    }

    sort(points.begin(), points.end());

    int cnt = 1, idx = 0;
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i-1] == points[i]) {
            cnt++;
        } else {
            if (cnt == n) {
                idx = i-1;
                break;
            }
            cnt = 1;
        }
    }

    cout << points[idx].first << " " << points[idx].second << "\n";
    return 0;
}

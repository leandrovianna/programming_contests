// Codeforces - Winner - 2A
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> points;
vector<pair<string, int>> scores;

int main() {
    int n;

    cin >> n;
    string s, winner;
    for (int i = 0, x; i < n; i++) {
        cin >> s >> x;
        if (points.find(s) == points.end()) {
            points[s] = 0;
        }
        points[s] += x;
        scores.push_back({s, points[s]});
    }

    int mx = 0;
    for (const auto &p : points) {
        mx = max(mx, p.second);
    }

    for (int i = 0; i < n; i++) {
        if (points[scores[i].first] == mx &&
                scores[i].second >= mx) {
            winner = scores[i].first;
            break;
        }
    }

    cout << winner << "\n";

    return 0;
}

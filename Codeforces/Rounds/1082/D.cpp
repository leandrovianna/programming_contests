// Codeforces - Maximum Diameter Graph - 1082D Edu Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<int> leaves;
    vector<pair<int, int>> v;
    vector<pair<int, int>> edges;

    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == 1)
            leaves.push_back(i);
        else
            v.push_back({i, x});
    }

    if (v.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }

    for (size_t i = 1; i < v.size(); i++) {
        edges.push_back({v[i-1].first, v[i].first});
        v[i].second--;
        v[i-1].second--;
    }

    if (v.size() > 1) {
        swap(v[1], v[v.size()-1]);
    }

    int last = -1;
    for (const auto &u : leaves) {
        int i = (last+1) % v.size();
        while (i != last) {
            if (v[i].second > 0) {
                break;
            }
            i = (i+1) % v.size();
        }

        if (v[i].second > 0) {
            edges.push_back({u, v[i].first});
            v[i].second--;
        } else {
            cout << "NO" << endl;
            return 0;
        }

        last = i;
    }

    int d = v.size() + min(2, (int) leaves.size()) - 1;
    cout << "YES " << d << "\n"; 
    cout << edges.size() << "\n"; 
    for (const auto &e : edges) {
        cout << e.first+1 << " " << e.second+1 << "\n";
    }
    return 0;
}

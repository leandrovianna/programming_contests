// Codeforces - Lunar New Year and Food Ordering - 1106B
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int64_t a[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    set<pair<int64_t, int>> ss;

    for (int i = 0; i < n; i++) {
        ss.insert({c[i], i});
    }

    int64_t d, cost;

    for (int i = 0, t; i < m; i++) {
        cin >> t >> d;
        t--;

        cost = 0;

        if (a[t] - d >= 0) {
            a[t] -= d;
            cost = d * c[t];
            d = 0;
        } else if (a[t] > 0) {
            cost = a[t] * c[t];
            d -= a[t];
            a[t] = 0;
        }

        while (!ss.empty() && d > 0) {
            auto it = ss.begin();
            if (a[it->second] - d >= 0) {
                a[it->second] -= d;
                cost += d * it->first;
                d = 0;
            } else if (a[it->second] > 0) {
                cost += a[it->second] * it->first;
                d -= a[it->second];
                a[it->second] = 0;
            } else {
                ss.erase(it);
            }
        }

        if (d > 0) {
            cost = 0;
        }

        cout << cost << "\n";
    }
    return 0;
}

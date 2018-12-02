#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t, n, k1, k2;

    cin >> t;

    while (t--) {
        vector<int> v;
        set<int> t2;
        cin >> n;
        for (int i = 1, x, y; i < n; i++) {
            cin >> x >> y;
        }

        cin >> k1;
        for (int i = 0, x; i < k1; i++) {
            cin >> x;
            v.push_back(x);
        }

        cin >> k2;
        for (int i = 0, x; i < k2; i++) {
            cin >> x;
            t2.insert(x);
        }

        int ans = -1;
        for (int ti = 0, x, y; ti < 5; ti++) {
            x = uniform_int_distribution<int>(0, k1-1)(rng);
            cout << "A " << v[x] << endl;
            cin >> y;

            if (t2.count(y)) {
                ans = x;
                break;
            }
        }

        cout << "C " << ans << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    int64_t x;
    multiset<int64_t> vl, ss;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        ss.insert(x);
        vl.insert(x);
    }

    int ans = 0;

    for (const auto &p : ss) {
        auto it = vl.upper_bound(p);

        if (it != vl.end()) {
            ans++;
            vl.erase(it);
        }
    }

    cout << ans << "\n";

    return 0;
}

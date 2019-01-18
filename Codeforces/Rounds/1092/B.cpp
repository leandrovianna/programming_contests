#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int N = 110;
    int n, a[N];

    cin >> n;
    set<int> ss;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (ss.find(x) != ss.end()) {
            ss.erase(x);
        } else {
            ss.insert(x);
        }
    }

    int k = 0;
    for (const auto &x : ss) {
        a[k++] = x;
    }

    sort(a, a+k);

    int ans = 0;
    for (int i = 0; i < k; i += 2) {
        ans += a[i+1] - a[i];
    }

    cout << ans << "\n";

    return 0;
}

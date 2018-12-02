#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    int64_t a, b, k, ans;

    cin >> t;

    while (t--) {
        cin >> a >> b >> k;
        ans = -b * (k / 2) + a * (k - k / 2);
        cout << ans << "\n";
    }
    return 0;
}

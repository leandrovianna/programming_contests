// Codeforces - Creating a Character - 1217A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, s, i, e;

    cin >> t;

    while (t--) {
        cin >> s >> i >> e;

        int lo = 0, hi = e, mid, ans = 0;

        while (lo <= hi) {
            mid = (lo + hi) / 2;

            if (s + mid > i + e - mid) {
                ans = e - mid + 1;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

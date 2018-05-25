// Codechef - May Long Challenge 2018 - Xor Again - XORAGN
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            ans ^= 2 * x;
        }

        cout << ans << endl;
    }
    return 0;
}

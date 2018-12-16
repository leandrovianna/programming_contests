// Codeforces - Dice Rolling - 1093A - Edu Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x;

    cin >> t;
    while (t--) {
        cin >> x;
        int ans = 0;
        while (x > 0) {
            if (x > 3) {
                x -= 2;
                ans++;
            } else {
                x -= 3;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

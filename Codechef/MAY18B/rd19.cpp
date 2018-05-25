//Codechef - Minimum Deletions - May Long Challenge 2018 Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t, n, x, acc_gcd;

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> acc_gcd;
        for (int i = 1; i < n; i++) {
            cin >> x;
            acc_gcd = __gcd(acc_gcd, x);
        }

        if (acc_gcd == 1) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}

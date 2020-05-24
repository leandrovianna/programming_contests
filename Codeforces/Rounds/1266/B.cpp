// Codeforces - Dice Tower
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    int64_t x;
    cin >> t;

    while (t--) {
        cin >> x;

        if (x >= 15 && x % 14 <= 6 && 1 <= x % 14) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

// Codeforces - Parity - 1110A Global Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int b, k;

    cin >> b >> k;

    int ans = 0;

    for (int i = k-1, x; i >= 0; i--) {
        cin >> x;
        if ((x & 1) && (i == 0 || (b & 1)))
            ans++;
    }

    ans %= 2;
    cout << (ans == 0 ? "even" : "odd") << "\n";
    return 0;
}

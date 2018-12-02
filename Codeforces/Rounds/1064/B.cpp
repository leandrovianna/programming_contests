// Codeforces - Equations on Mathematical Magic - 1064B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a;

    cin >> t;
    while (t--) {
        cin >> a;
        cout << (1LL << __builtin_popcount(a)) << "\n";
    }
    return 0;
}

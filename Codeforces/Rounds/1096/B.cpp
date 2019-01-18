// Codeforces - Substring Removal - 1096B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string s;

    cin >> n >> s;

    int64_t c1 = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            c1++;
        } else {
            break;
        }
    }

    int64_t c2 = 1;
    for (int i = n-2; i >= 0; i--) {
        if (s[i] == s[i+1]) {
            c2++;
        } else {
            break;
        }
    }

    const int mod = 998244353;
    int64_t ans = (s[0] == s[n-1]) ? (c1+1) * (c2+1) : c1 + c2 + 1;
    ans %= mod;

    cout << ans << "\n";
    return 0;
}

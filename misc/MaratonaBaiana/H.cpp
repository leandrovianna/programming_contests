#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;

    int64_t ans = 0;
    for (int64_t i = 1; i <= n; i *= 2LL) {
        ans++;
    }

    cout << ans << "\n";
    return 0;
}

//AtCoder - Remainder Reminder - Regular 091
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    if (k == 0) {
        cout << (int64_t)n * n << endl;
        return 0;
    }

    int64_t ans = (n - k + 1) * (n - k) / 2;

    for (int i = 2; i <= n; i++) {
        int j = i + k;
        if (j > n) break;
        ans += (n - j + 1) - (n - i + 1) / i;
    }

    cout << ans << endl;
    return 0;
}

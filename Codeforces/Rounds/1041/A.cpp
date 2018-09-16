// Codeforces - Heist - 1041A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int N = 1010;
    int n;
    int64_t a[N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int64_t ans = 0;
    for (int i = 1; i < n; i++) {
        ans += a[i] - a[i-1] - 1;
    }

    cout << ans << "\n";

    return 0;
}

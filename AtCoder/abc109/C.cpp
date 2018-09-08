// AtCoder - Skip - abc109C
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
int64_t a[N], x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n >> x;

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans = __gcd(ans, abs(x - a[i]));
    }

    cout << ans << endl;

    return 0;
}

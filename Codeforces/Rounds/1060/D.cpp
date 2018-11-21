// Codeforces - Social Circles - 1060D Div1+Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64_t ans = 0;
    int l[N], r[N];

    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        l[i] = x;
        r[i] = y;
    }

    sort(l, l+n);
    sort(r, r+n);

    for (int i = 0; i < n; i++) {
        ans += 1 + max(l[i], r[i]);
    }

    cout << ans << endl;

    return 0;
}

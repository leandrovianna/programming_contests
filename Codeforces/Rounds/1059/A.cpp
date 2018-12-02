// Codeforces - Cashier - 1059A Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
pair<int, int> cus[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, a;

    cin >> n >> l >> a;

    cus[0] = {0, 0};
    for (int i = 1, li; i <= n; i++) {
        cin >> cus[i].first >> li;
        cus[i].second = cus[i].first + li;
    }
    cus[n+1] = {l, l};

    int64_t ans = 0;
    for (int i = 1, d; i <= n+1; i++) {
        d = cus[i].first - cus[i-1].second;
        ans += d / a;
    }

    cout << ans << endl;
    return 0;
}

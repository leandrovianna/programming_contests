// Codeforces - Make It Equal - 1065C Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int64_t h[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int64_t k, ans, max_height, min_height;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h, h+n);
    min_height = *min_element(h, h+n);
    max_height = *max_element(h, h+n);

    int64_t acc_cost = 0;
    ans = 0;
    for (int i = max_height; i >= min_height; i--) {
        int cost = h+n - lower_bound(h, h+n, i+1);

        if (acc_cost + cost <= k) {
            acc_cost += cost;
        } else {
            ans++;
            acc_cost = cost;
        }
    }

    if (acc_cost > 0) {
        ans++;
    }

    cout << ans << "\n";
    return 0;
}

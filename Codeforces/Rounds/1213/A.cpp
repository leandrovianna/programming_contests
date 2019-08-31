// Codeforces - Chips Moving - 1213A Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int64_t inf = 1e18;
    int64_t ans = inf;

    for (int i = 0; i < n; i++) {
        int64_t lcost = 0;
        for (int j = 0; j < n; j++) {
            lcost += abs(a[i] - a[j]) % 2;
        }

        ans = min(ans, lcost);
    }

    cout << ans << "\n";
    return 0;
}

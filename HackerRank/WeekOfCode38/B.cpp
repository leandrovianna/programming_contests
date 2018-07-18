#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int N = 100 * 1000 + 10;
    int n;
    int64_t k, a[N];
    map<int64_t, int> cnt;

    int max_app = 0;
    int64_t x;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        x = a[i] - i * k;
        cnt[x]++;

        if (max_app < cnt[x]) {
            max_app = cnt[x];
        }
    }

    int ans = n - max_app;

    cout << ans << endl;
    return 0;
}

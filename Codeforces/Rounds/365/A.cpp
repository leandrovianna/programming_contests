#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int cnt[10];
    int ans = 0;

    cin >> n >> k;

    for (int i = 0, x; i < n; i++) {
        cin >> x;

        memset(cnt, 0, sizeof(cnt));

        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }

        bool good = true;
        for (int j = 0; j <= k; j++) {
            if (cnt[j] == 0) {
                good = false;
                break;
            }
        }

        if (good)
            ans++;
    }

    cout << ans << endl;
    return 0;
}

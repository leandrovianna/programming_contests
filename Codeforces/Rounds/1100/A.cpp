// Codeforces - Roman and Browser - 1100A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 110;
    int n, k, a[N];

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for (int b = 0, e, s; b < n; b++) {
        e = 0;
        s = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 1)
                e++;
            else
                s++;
        }

        for (int i = b; i < n; i += k) {
            if (a[i] == 1) {
                e--;
            } else {
                s--;
            }
        }

        for (int i = b - k; i >= 0; i -= k) {
            if (a[i] == 1) {
                e--;
            } else {
                s--;
            }
        }

        ans = max(ans, abs(e - s));
    }

    cout << ans << endl;
    return 0;
}

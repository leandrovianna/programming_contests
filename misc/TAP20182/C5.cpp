// TAP 2018/2 - Soma máxima
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n, k, a[N];

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    for (int i = 0; i < n; i++) {
        if (k == 0)
            break;

        if (a[i] < 0) {
            a[i] = -a[i];
            k--;
        } else {
            break;
        }
    }

    sort(a, a+n);

    if (k % 2) {
        a[0] = -a[0];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}

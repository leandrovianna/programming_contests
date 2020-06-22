// TAP 2018/2 - C7 - Help Cupid
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1010;
    int n, a[N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int ans1 = 0, ans2 = 0;

    ans1 = min(abs(a[0] - a[n-1]), 24 - abs(a[0] - a[n-1]));
    for (int i = 1; i < n-1; i += 2) {
        ans1 += min(abs(a[i] - a[i+1]), 24 - abs(a[i] - a[i+1]));
    }

    for (int i = 0; i < n; i += 2) {
        ans2 += min(abs(a[i] - a[i+1]), 24 - abs(a[i] - a[i+1]));
    }

    cout << min(ans1, ans2) << endl;
    return 0;
}

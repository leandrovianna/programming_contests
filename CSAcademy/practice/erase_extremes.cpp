#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1010;
    int n, mx = 0, me = 10100;
    int a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        me = min(me, a[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != mx && a[i] != me)
            sum += a[i];
    }

    cout << sum << endl;
    return 0;
}

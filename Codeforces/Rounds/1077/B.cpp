#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int N = 110;
    int n, ans = 0;
    int a[N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n-1; i++) {
        if (a[i-1] == 1 && a[i+1] == 1 && a[i] == 0) {
            ans++;
            a[i+1] = 0;
        }
    }

    cout << ans << endl;
    return 0;
}

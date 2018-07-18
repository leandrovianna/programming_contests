// Codeforces - Mishka and Contest - 999A Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1010;
    int n, k;
    int a[N];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0, j = n-1;
    for (int i = 0; i < n; i++) {
        if (a[i] <= k)
            ans++;
        else {
            j = i;
            break;
        }
    }

    for (int i = n-1; i > j; i--) {
        if (a[i] <= k)
            ans++;
        else
            break;
    }

    cout << ans << endl;
    return 0;
}

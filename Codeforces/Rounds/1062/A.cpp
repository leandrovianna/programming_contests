#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n, a[N];

    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n+1] = 1001;

    int l_ans = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i-1] + 1 && a[i] == a[i+1] - 1) {
            l_ans++;
        } else {
            l_ans = 0;
        }

        ans = max(l_ans, ans);
    }

    cout << ans << endl;
    return 0;
}

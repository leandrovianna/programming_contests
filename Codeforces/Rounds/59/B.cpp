// Codeforeces - Fortune Telling - 59B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int ans = 0, count = 0, mx = 1e9;

    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ans += x;
        if (x % 2 == 1) {
            mx = min(mx, x);
            count++;
        }
    }

    if (ans % 2 == 0) {
        if (count > 0) {
            ans -= mx;
        } else {
            ans = 0;
        }
    }

    cout << ans << endl;

    return 0;
}

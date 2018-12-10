// Codeforces - The Fair Nut and Elevator - 1084A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n, a[N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 1e9;
    for (int x = 1; x <= n; x++) {
        int lans = 0;
        for (int i = 1; i <= n; i++) {
            lans += 2 * a[i-1] * (abs(x - i) + abs(i - 1) + abs(1 - x));
        }

        ans = min(ans, lans);
    }

    cout << ans << endl;
    return 0;
}

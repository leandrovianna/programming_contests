// Codeforces - Not so Simple Polygon Embedding - 1354C2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;

    cout << fixed << setprecision(10);

    cin >> t;
    while (t--) {
        cin >> n;

        const double PI = acos(-1);
        double ans = cos(PI / (4*n)) / sin(PI / (2*n));
        cout << ans << "\n";
    }
    return 0;
}

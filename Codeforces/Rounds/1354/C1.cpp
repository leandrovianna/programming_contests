// Codeforces - Simple Polygon Embedding - 1354C1
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        const double PI = acos(-1);
        const double l = 1 / tan(PI / (2*n));
        cout << fixed << setprecision(10) << l << "\n";
    }
    return 0;
}

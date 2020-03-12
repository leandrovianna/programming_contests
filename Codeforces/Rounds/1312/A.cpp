// Codeforces - Two Regular Polygons - 1312A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << (n % m == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}

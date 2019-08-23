// Codeforces - 1204B - Mislove has load an Array
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r;

    cin >> n >> l >> r;

    int64_t mi = n - l, ma = (1LL << (r-1)) * (n - r);

    int64_t p = 1;
    for (int i = 0; i < l; i++) {
       mi += p; 
       p *= 2;
    }

    p = 1;
    for (int i = 0; i < r; i++) {
        ma += p;
        p *= 2;
    }

    cout << mi << " " << ma << "\n";
    return 0;
}

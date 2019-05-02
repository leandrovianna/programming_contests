// UVA - Feynman - 12149
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;

    while (cin >> n, n) {
        int64_t ans = n * (n + 1) * (2 * n + 1) / 6;
        cout << ans << "\n";
    }
    return 0;
}

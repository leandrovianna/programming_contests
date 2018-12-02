// Codeforces - Vasya and Chocolate - 1065A Edu Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int64_t s, a, b, c;

    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        cin >> s >> a >> b >> c;
        int64_t ans = s / c + ((s / c) / a) * b;
        cout << ans << endl;
    }
    return 0;
}

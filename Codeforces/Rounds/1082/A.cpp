// Codeforces - Vasya and Book - 1082A Edu Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int64_t n, x, y, d;

    cin >> t;
    while (t--) {
        cin >> n >> x >> y >> d;

        if (abs(x - y) % d == 0)
            cout << abs(x - y) / d << "\n";
        else {
            int64_t ans1 = 1e9, ans2 = 1e9;
            if (abs(1 - y) % d == 0)
                ans1 = abs(1 - y) / d + (abs(1 - x) + d - 1) / d;
            
            if (abs(n - y) % d == 0)
                ans2 = abs(n - y) / d + (abs(n - x) + d - 1) / d;

            if (ans1 == 1e9 && ans2 == 1e9)
                cout << "-1\n";
            else
                cout << min(ans1, ans2) << "\n";
        }
    }
    return 0;
}

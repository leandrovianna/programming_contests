// Codeforces - 1207A - There are two types of burgers
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;

    int b, p, f, h, c;

    while (t--) {
        cin >> b >> p >> f;
        cin >> h >> c;

        int maxprofit = 0;
        for (int b1 = 0, b2 = b; b1 <= b; b1++, b2--) {
            int profit = h * min(b1 / 2, p) + c * min(b2 / 2, f); 
            maxprofit = max(maxprofit, profit);
        }

        cout << maxprofit << "\n";
    }
    return 0;
}

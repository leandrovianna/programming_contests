// UVA Online Judge - 357 - Let Me Count The Ways
#include <bits/stdc++.h>
using namespace std;

const int W = 30010;
int64_t dp[W];

int main() {
    int n;

    dp[0] = 1;
    for (int w = 1; w < W; w++) {
        dp[w] = 0;
    }

    for (const auto &c : {1, 5, 10, 25, 50}) {
        for (int w = 1; w < W; w++) {
            if (w - c >= 0)
                dp[w] += dp[w-c];
        }
    }

    while (cin >> n) {
        int64_t &ans = dp[n];

        if (ans == 1)
            cout << "There is only 1 way ";
        else
            cout << "There are " << ans << " ways ";

        cout << "to produce " << n << " cents change.\n";
    }
    return 0;
}

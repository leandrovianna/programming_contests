// Codeforces - Win or Freeze - 151C Div2
#include <bits/stdc++.h>
using namespace std;

map<int64_t, bool> dp;

bool compute(int64_t q) {
    if (dp.count(q)) {
        return dp[q];
    }

    bool ans = true;

    for (int64_t di = 2, k; di * di <= q; di++) {
        if (q % di == 0) {
            ans = false;

            if (!compute(di)) {
                ans = true;
                break;
            }

            k = q / di;
            if (k != q && !compute(k)) {
                ans = true;
                break;
            }
        }
    }

    return dp[q] = ans;
}

int main() {
    int64_t q;

    cin >> q;

    bool ans = compute(q);
    cout << (ans ? 1 : 2) << endl;
    if (ans) {
        int64_t x = 0;
        for (int64_t di = 2, k; di * di <= q; di++) {
            if (q % di == 0) {
                if (!dp[di]) {
                    x = di;
                    break;
                }
                k = q / di;
                if (k != q && !dp[k]) {
                    x = k;
                    break;
                }
            }
        }

        cout << x << endl;
    }
    return 0;
}

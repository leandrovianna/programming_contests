// UVA - The Monkey and the Oiled Bamboo - 12032
#include <bits/stdc++.h>
using namespace std;

bool check(int rungs[], const int n, int k) {
    int height = 0;
    for (int i = 0; i < n; i++) {
        if (height + k < rungs[i]) {
            return false;
        }

        if (height + k == rungs[i])
            k--;

        height = rungs[i];
    }

    return true;
}

int main() {
    const int N = 100 * 1000 + 10;
    int t, n, rungs[N];

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> rungs[i];
        }

        int lo = 1;
        int hi = 1000 * 1000 * 10;
        int mid, ans = hi;

        while (lo <= hi) {
            mid = (hi - lo) / 2 + lo;

            if (check(rungs, n, mid)) {
                hi = mid-1;
                ans = mid;
            } else {
                lo = mid+1;
            }
        }

        cout << "Case " << ti << ": " << ans << endl;
    }
    return 0;
}

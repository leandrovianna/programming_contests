//Codeforces - Three-level laser - 957C Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int n, u;
int e[N];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> u;
    for (int i = 0; i < n; i++)
        cin >> e[i];

    bool no_ans = true;
    double ans = 0;

    for (int i = 0; i < n-2; i++) {
        int hi = n-1;
        int lo = i+2;
        int mid;

        // cout << "i " << i << " lo " << lo << " hi " << hi << endl;
        while (lo <= hi) {
            mid = (hi + lo) >> 1;

            // cout << mid << endl;

            if (e[mid] - e[i] <= u) {
                // cout << "< u" << endl;

                ans = max(ans, (e[mid] - e[i+1]) / ((double)e[mid] - e[i]));
                no_ans = false;

                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
    }

    // for (int i = 0; i < n-2; i++) {
    //     int k = n-1;
    //     while (e[k] - e[i] > u) {
    //         k--;
    //     }
    //
    //     if (k > i+1) {
    //         // cout << e[i] << " " << e[i+1] << " " << e[k] << endl;
    //         // cout << (e[k] - e[i+1]) / ((double)e[k] - e[i]) << endl;
    //         ans = max(ans, (e[k] - e[i+1]) / ((double)e[k] - e[i]));
    //         no_ans = false;
    //     }
    // }

    if (no_ans) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}

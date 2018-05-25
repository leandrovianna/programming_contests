//Codechef - Average of Pairs - April Challenge
#include <bits/stdc++.h>
using namespace std;

const int N = 100100, M = 2100;
int t, n, a[N];
uint64_t cnt[M];

int main() {
    const int A = 1010;
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[A + a[i]]++;
        }

        uint64_t ans = 0;
        for (int i = -A; i <= A; i++) {
            if (cnt[A + i]) {
                ans += cnt[A + i] * (cnt[A + i]-1) / 2;
            }
        }

        uint64_t ans2 = 0;
        for (int i = -A; i <= A; i++) {
            for (int j = -A; j <= A; j++) {
                if (i != j && (i & 1) == (j & 1)
                        && cnt[A + i] && cnt[A + j]
                        && cnt[(2 * A + i + j) / 2]) {
                    ans2 += cnt[A + i] * cnt[A + j];
                }
            }
        }

        ans += ans2 / 2;

        cout << ans << endl;
    }
}

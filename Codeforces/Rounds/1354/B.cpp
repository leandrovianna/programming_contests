// Codeforces - Ternary String - 1354B
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    string s;
    cin >> t;

    int cnt[4];

    while (t--) {
        cin >> s;

        const int n = s.size();
        int mid, hi = n, lo = 1, ans = 0;

        while (lo <= hi) {
            mid = (lo + hi) >> 1;

            // check
            bool check = false;

            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < mid; i++) {
                cnt[s[i] - '0']++;
            }

            // test for (p-mid, p)
            for (int p = mid-1; p < n; p++) {
                check = true;
                for (int v = 1; v <= 3; v++) {
                    check = check && (cnt[v] > 0);
                }

                if (check) {
                    break;
                }

                cnt[s[p-mid+1] - '0']--;
                if (p+1 < n)
                    cnt[s[p+1] - '0']++;
            }

            if (check) {
                hi = mid-1;
                ans = mid;
            } else {
                lo = mid+1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

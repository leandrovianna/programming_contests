//Codejam 2018 - Round 1B - Rounding Error
#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t, int64_t> ll;

const int N = 100100;
ll a[N];

bool is_roundedup(int64_t x, int64_t n) {
    int64_t ceilhalfn = n / 2 + n % 2;
    return ((x * 100) % n >= ceilhalfn);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    int64_t n, l;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        set<int> roundups;
        cin >> n >> l;
        int64_t c = 0; // person available
        for (int i = 0; i < l; i++) {
            cin >> a[i].second;
            c += a[i].second;
        }

        c = n - c;

        int64_t ceiln = n / 2 + n % 2;
        for (int i = 1; i <= n; i++) {
            if ((i * 100) % n >= ceiln) {
                roundups.insert(i);
            }
        }

        if (roundups.size() == 0)
            roundups.insert(1);

        for (int i = 0; i < l; i++) {
            auto it = roundups.lower_bound(a[i].second);
            if (it != roundups.end()) {
                a[i].first = *it - a[i].second;
            }
        }

        for (int i = l; i < l+c; i++) {
            a[i].first = *roundups.begin();
            a[i].second = 0;
        }
        l = l+c; //new size

        sort(a, a+l);

        int i = 0;
        while (i < l && c > 0) {
            if (a[i].first != 0 && a[i].first <= c) {
                a[i].second += a[i].first;
                c -= a[i].first;
            }
            i++;
        }

        i = 0;
        while (i < l && c > 0) {
            if (!is_roundedup(a[i].second, n)) {
                a[i].second += c;
                break;
            }
            i++;
        }

        int64_t ans = 0;
        for (int i = 0; i < l; i++) {
            ans += 100 * a[i].second / n;

            if (is_roundedup(a[i].second, n))
                ans++;
        }
        cout << "Case #" << ti << ": " << ans << "\n";
    }

    return 0;
}

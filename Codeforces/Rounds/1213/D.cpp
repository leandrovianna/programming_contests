// Codeforces - Equalizing By Division (hard version) - 1213D2 Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
const int64_t inf = 1e18;
int64_t pf[N], a[N];

int64_t calc(int x, int k) {
    int64_t x1 = 2*x, x2 = 2*x+1, 
            cnt = x > 0 ? pf[x] - pf[x-1] : 0;

    int64_t lans = 0, p = 1;

    for (; cnt < k && x1 < N; x1 = 2*x1, x2 = 2*x2+1) {
        x2 = min(x2, int64_t{N-1});

        int q = pf[x2] - pf[x1-1];
        // cout << "from " << x1 << " to " << x2  << ", q: " << q << endl;

        if (q >= k - cnt) {
            lans += (k - cnt) * p;
            cnt = k;
        } else {
            lans += q * p;
            cnt += q;
        }

        p++;
    }

    if (cnt >= k) {
        return lans;
    }

    return inf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pf[a[i]]++;
    }

    for (int x = 1; x < N; x++) {
        pf[x] += pf[x-1];
    }

    int64_t ans = inf;

    for (int x = 1; x < N; x++) {
        ans = min(ans, calc(x, k));
    }

    cout << ans << "\n";
    return 0;
}

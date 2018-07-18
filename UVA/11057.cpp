// UVA - Exact Sum - 11057
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100 * 1000;
    int n;
    int64_t a[N];
    int64_t m;
    int64_t ans;
    auto sol = pair<int, int>{-1, -1};

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cin >> m;

        sort(a, a+n);
        
        ans = 1e9;

        for (int i = 0; i < n; i++) {
            int lo = i+1, hi = n-1, mid;

            while (lo <= hi) {
                mid = (lo + hi) / 2;

                if (a[mid] + a[i] > m) {
                    hi = mid-1;
                } else if (a[mid] + a[i] <= m) {
                    lo = mid+1;

                    if (a[mid] + a[i] == m && ans > a[mid] - a[i]) {
                        assert(a[mid] - a[i] >= 0);
                        ans = a[mid] - a[i];
                        sol = {i, mid};
                    }
                }
            }
        }

        cout << "Peter should buy books whose prices are "
            << a[sol.first] << " and " << a[sol.second] << "."
            << "\n\n";
    }
    return 0;
}

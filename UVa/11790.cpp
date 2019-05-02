// UVA - Murcia's Skyline - 11790
#include <bits/stdc++.h>
using namespace std;

struct Building {
    int w, h;
};

namespace LIS {
    const int N = 100 * 1000 + 10;
    int l[N], l_id[N], l_end, f[N];

    int lis(Building a[], const int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            f[i] = a[i].w;
            for (int j = 0; j < i; j++) {
                if (a[j].h < a[i].h) {
                    f[i] = max(f[i], f[j] + a[i].w);
                }
            }

            ans = max(ans, f[i]);
        }
        /*
        l_end = 0;
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(l, l+l_end, a[i].h) - l;

            if (pos == l_end || a[l_id[pos]].w <= a[i].w) {
                l[pos] = a[i].h;
                l_id[pos] = i;
            }

            f[i] = a[i].w + (pos > 0 ? f[l_id[pos-1]] : 0);

            if (pos == l_end) {
                l_end++;
            }

            ans = max(ans, f[i]);
        }
        */

        return ans;
    }
}

namespace LDS {
    const int N = 100 * 1000 + 10;
    int l[N], l_id[N], f[N], l_end;

    int lds(Building a[], const int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            f[i] = a[i].w;
            for (int j = 0; j < i; j++) {
                if (a[j].h > a[i].h) {
                    f[i] = max(f[i], f[j] + a[i].w);
                }
            }

            ans = max(ans, f[i]);
        }
        /*
        l_end = 0;

        for (int i = 0; i < n; i++) {
            int pos = lower_bound(l, l+l_end, a[i].h, greater<int>()) - l;

            if (pos == l_end || a[l_id[pos]].w <= a[i].w) {
                l[pos] = a[i].h;
                l_id[pos] = i;
            }

            f[i] = a[i].w + (pos > 0 ? f[l_id[pos-1]] : 0);

            if (pos == l_end) {
                l_end++;
            }

            ans = max(ans, f[i]);
        }
        */

        return ans;
    }
}

int main() {
    int t, n;
    const int N = 100 * 1000 + 10;
    Building a[N];

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].h;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i].w;
        }

        int lis_len = LIS::lis(a, n);
        int lds_len = LDS::lds(a, n);

        cout << "Case " << ti << ". ";

        if (lis_len >= lds_len) {
            cout << "Increasing (" << lis_len << "). "
                << "Decreasing (" << lds_len << ").\n";
        } else {
            cout << "Decreasing (" << lds_len << "). "
                << "Increasing (" << lis_len << ").\n";
        }
    }
    return 0;
}

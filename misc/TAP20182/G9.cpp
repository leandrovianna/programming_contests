// TAP 2018/2 - Campeonato de arco e flecha - G9
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
int64_t pref[N];
pair<int64_t, int64_t> a[N];

void calc(int n) {
    for (int i = 0; i < n; i++) {
        pref[i] = a[i].second + (i == 0 ? 0 : pref[i-1]);
    }
}

int main() {
    int n, q;
    int lo, hi, mid;
    int64_t x, y;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n);

    calc(n);

    for (int i = 0, t; i < q; i++) {
        cin >> t;
        switch (t) {
            case 1: 
                lo = 0;
                hi = n-1;
                cin >> x;

                while (lo <= hi) {
                    mid = (lo + hi) / 2;

                    if (a[mid].first == x) {
                        cout << pref[mid] << "\n";
                        break;
                    } else if (a[mid].first < x) {
                        lo = mid+1;
                    } else {
                        hi = mid-1;
                    }
                }
                
                break;
            case 2:
                cin >> x >> y;
                lo = 0;
                hi = n-1;
                while (lo <= hi) {
                    mid = (lo + hi) / 2;

                    if (a[mid].first == x) {
                        a[mid].second = y;
                        calc(n);
                        break;
                    } else if (a[mid].first < x) {
                        lo = mid+1;
                    } else {
                        hi = mid-1;
                    }
                }
                break;
        }
    }
    return 0;
}

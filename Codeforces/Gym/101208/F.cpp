// Codeforces - Low Power - ICPC World Finals 2013 - F
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;
    const int s = 2*n*k;
    for (int i = 0; i < s; i++) {
        cin >> a[i];
    }
    
    sort(a, a+s);

    int lo = 0, hi = 1e9-1, mid, ans = 0;

    while (lo <= hi) {
        mid = (hi - lo) / 2 + lo;

        bool check = true;
        if (a[1] - a[0] > mid) {
            check = false;
        } else {
            int limit = 2*k, m = 1;
            for (int i = 2; m < n && i < s-1; i++) {
                if (a[i+1] - a[i] <= mid) {
                    m++;
                    i++;
                    limit += 2*k;
                } else if (i == limit) {
                    check = false;
                    break;
                }
            }

            if (m != n)
                check = false;
        }

        if (check) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    cout << ans << "\n";

    return 0;
}

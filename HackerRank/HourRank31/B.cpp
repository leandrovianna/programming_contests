// Hackerrank - HourRank 31 - Save the queen - 2nd
#include <bits/stdc++.h>
using namespace std;

const int N = 10100;
int a[N];

int main() {
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    double low = 0, high = 1e12, mid;
    int64_t remaining;

    for (int it = 0; it < 500; it++) {
        mid = (low + high) / 2;

        int inv = n;
        remaining = 0;
        for (int i = 0; i < k; i++) {
            if (a[i] >= mid) {
                inv--;
            } else {
                remaining += a[i];
            }
        }

        if (inv <= 0) {
            low = mid;
        } else {
            if ((double) remaining / inv >= mid)
                low = mid;
            else
                high = mid;
        }
    }

    cout << setprecision(10) << fixed;
    cout << low << endl;
    return 0;
}

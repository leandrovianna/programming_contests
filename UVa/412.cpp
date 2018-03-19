//UVa - Pi - UVA 412
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    const int N = 55;
    int n, count = 0;
    int a[N];

    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (__gcd(a[i], a[j]) == 1) {
                    count++;
                }
            }
        }

        if (count == 0) {
            cout << "No estimate for this data set." << endl;
        } else {
            double y = n * (n-1) / 2.0;
            double ans = sqrt(6.0 * y / (double) count);
            cout << fixed << setprecision(6) << ans << endl;
        }
    }

    return 0;
}

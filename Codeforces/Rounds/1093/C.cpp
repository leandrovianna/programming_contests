// Codeforces - Mishka and the Last Exam - 1093C
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100100;
int64_t a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n/2; i++) {
        cin >> b[i];
    }

    // A0 = B0 - An-1
    a[0] = 0;
    a[n-1] = b[0];

    int64_t low, high, mid, v, u;
    for (int i = 1; i < n/2; i++) {
        low = a[i-1];
        high = min(b[i] / 2, a[n-i]);
        u = -1;

        while (low <= high) {
            mid = (high + low) / 2;
            v = b[i] - mid;

            if (mid <= v && low <= v && v <= a[n-i]) {
                u = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        assert(u != -1);

        a[i] = u;
        a[n-i-1] = b[i] - u;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}

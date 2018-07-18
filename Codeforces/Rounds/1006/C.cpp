#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int64_t a[N];

int main() {
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int p1 = -1, p2 = n;
    int64_t sum1 = 0, sum3 = 0;
    int64_t ans = 0;

    while (p1 < p2) {
        if (sum1 == sum3) {
            ans = max(ans, sum1);
        }

        if (sum1 <= sum3) {
            p1++;
            sum1 += a[p1];
        }

        if (sum1 > sum3) {
            p2--;
            sum3 += a[p2];
        }
    }

    cout << ans << endl;
    return 0;
}

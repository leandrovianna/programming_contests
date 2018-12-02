// Codeforces - Berland Fair - 1073D Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int64_t a[N], sum;

int main() {
    int n;
    int64_t t;

    cin >> n >> t;

    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = 0;
    while (t > 0) {
        cout << t << endl;
        ans += t / sum;
        t %= sum;

        for (int i = 0; i < n; i++) {
            if (a[i] > t) {
                ans--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// Codeforces - Just Eat It! - 1285B
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int64_t a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int64_t sum = 0, maxsum = a[0], total = 0;

        for (int i = 0; i < n; i++) {
            total += a[i];
            sum += a[i];

            maxsum = max(maxsum, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        if (total > maxsum) {
            cout << "YES\n";
        } else if (total < maxsum) {
            cout << "NO\n";
        } else {
            bool ans = true;

            sum = 0;
            for (int i = 0; i < n-1; i++) {
                sum += a[i];
                if (sum == 0) {
                    ans = false;
                    break;
                }
            }

            sum = 0;
            for (int i = n-1; i > 0; i--) {
                sum += a[i];
                if (sum == 0) {
                    ans = false;
                    break;
                }
            }

            cout << (ans ? "YES\n" : "NO\n");
        }
    }

    return 0;
}

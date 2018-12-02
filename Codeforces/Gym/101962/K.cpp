#include <bits/stdc++.h>
using namespace std;

const int N = 50100;
int64_t a[N], pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = a[i] + (i == 0 ? 0 : pref[i-1]);
    }

    for (int pos = 0; pos < n; pos++) {
        int64_t sum = 0;
        for (int i = pos, inc = 3; i < n; i += inc, inc += 3) {
            int64_t v = pref[min(n-1, i + inc - 1)] 
                - (i > 0 ? pref[i-1] : 0);

            if (v > 0)
                sum += v;
        }

        cout << sum << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    const int64_t INF = 1000 * 1000 * 1000 * 1000LL * 1000 * 1000;
    ios::sync_with_stdio(false);

    const int N = 3010;
    int n;
    int64_t s[N], c[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin  >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int64_t m[N];
    for (int i = 0; i < n; i++) {
        int64_t cost = INF;
        for (int j = i+1; j < n; j++) {
            if (s[i] < s[j]) {
                cost = min(cost, c[j]);
            }
        }
        m[i] = cost;
    }

    int64_t ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (s[i] < s[j]) {
                ans = min(ans,
                        c[i] + c[j] + m[j]);
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;
}

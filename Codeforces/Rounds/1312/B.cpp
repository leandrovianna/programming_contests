// Codeforces - Bogosort - 1312B
#include <bits/stdc++.h>
using namespace std;

const int M = 110;
int cnt[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        memset(cnt, 0, sizeof(cnt));

        cin >> n;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            cnt[x]++;
        }

        for (int v = 100; v >= 1; v--) {
            for (int i = 0; i < cnt[v]; i++) {
                cout << v << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

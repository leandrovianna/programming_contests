#include <bits/stdc++.h>
using namespace std;

const int E = 30;
int cnt[E];

int main() {
    int t, n;
    string s;

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < n; i++) {
            cin >> s;
            cnt[s.back() - 'A']++;
        }

        int ans = n;
        for (int e = 0; e < E; e++) {
            ans -= cnt[e] & 1;
        }

        cout << "Case #" << ti << ": " << ans << "\n";
    }
    return 0;
}

// Codeforces - Angry Students - 1287A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t;

    string s, s2;
    while (t--) {
        cin >> k >> s;
        s2 = s;

        int ans = 0;
        do {
            s = s2;
            for (int i = 0; i < k-1; i++) {
                if (s[i] == 'A')
                    s2[i+1] = 'A';
            }
            ans++;
        } while (s != s2);

        cout << ans-1 << "\n";
    }
    return 0;
}

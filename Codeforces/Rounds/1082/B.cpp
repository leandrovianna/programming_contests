// Codeforces - Vova and Trophies - 1082B Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N], pre[N], suf[N];

int main() {
    int n, t;
    string s;
    cin >> n >> s;

    int acc = 0;
    t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            t++;
            acc++;
        }
        else
            acc = 0;

        pre[i] = acc;
    }

    acc = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'G')
            acc++;
        else
            acc = 0;

        suf[i] = acc;
    }

    int ans = (t == n ? t : 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            int x = (i > 0 ? pre[i-1] : 0);
            int y = (i < n-1 ? suf[i+1] : 0);

            if (x + y < t) {
                ans = max(ans, x + y + 1);
            } else {
                ans = max(ans, x + y);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// Codeforces - Nauuo and Cards - 1173C
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N], b[N], s[N];
bool mark[N];
const int inf = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        mark[a[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        s[i] = b[i];
    }

    int ans = 0;

    int p = 0;

    for (int x = 1; x <= n; x++) {
        if (!mark[x]) continue;

        ans++;
        mark[s[p]] = true;
        s[p] = x;
        mark[x] = false;

        p++;
        if (p == n)
            p = 0;
    }

    for (int x = 1; x <= n; x++) {
        if (s[p] != x) {
            ans = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != 0) {
                    ans = max(ans, - a[i] + 1 + n);
                }
            }

            for (int i = 0; i < n; i++) {
                if (b[i] != 0) {
                    ans = max(ans, (i+1) - b[i] + 1 + n);
                }
            }

            break;
        }

        p++;
        if (p == n)
            p = 0;
    }
    
    cout << ans << "\n";

    return 0;
}

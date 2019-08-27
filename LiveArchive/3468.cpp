// Live Archive - Tornado! - 3468 - Latin America 2005
#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1 && idx == -1)
                idx = i;
        }

        if (idx == -1) {
            cout << (n+1) / 2 << "\n";
        } else {
            int i = (idx + 1) % n;
            int ans = 0;
            while (i != idx) {
                if (a[i] == 0 && a[(i + 1) % n] == 0) {
                    a[(i + 1) % n] = 1;
                    ans++;
                }

                i = (i + 1) % n;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

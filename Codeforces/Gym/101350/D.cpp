#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                cnt1++;
            } else {
                cnt2++;
            }
        }

        if (cnt1 == n || cnt2 == n) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}

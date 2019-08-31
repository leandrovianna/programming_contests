// Codeforces - Bad Prices - 1213B Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int minimum = 1e9;
        int bad_days = 0;

        for (int i = n-1; i >= 0; i--) {
            if (a[i] > minimum) {
                bad_days++;
            }

            minimum = min(minimum, a[i]);
        }

        cout << bad_days << "\n";
    }
    return 0;
}

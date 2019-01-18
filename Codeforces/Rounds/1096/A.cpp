// Codeforces - Find Divisible - 1096A Edu Round 57
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, l, r;

    cin >> t;

    while (t--) {
        cin >> l >> r;
        for (int i = l, j; i <= r; i++) {
            j = i * 2;
            if (l <= j && j <= r) {
                cout << i << " " << j << "\n";
                break;
            }
        }
    }
    return 0;
}

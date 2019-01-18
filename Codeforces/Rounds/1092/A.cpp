#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        int j = 0;
        for (int i = 0; i < n; i++) {
            cout << (char)('a' + j);
            j++;
            j %= k;
        }
        cout << "\n";
    }
    return 0;
}

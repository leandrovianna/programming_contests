// Codeforces - Digits Sequence Dividing - 1107A
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 310;
    int q, n, d[N];

    cin >> q;
    
    while (q--) {
        cin >> n;
        char ch;
        for (int i = 0; i < n; i++) {
            cin >> ch;
            d[i] = ch - '0';
        }

        if (n == 2 && d[0] >= d[1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n2\n";
            cout << d[0] << " ";
            for (int i = 1; i < n; i++) {
                cout << d[i];
            }
            cout << "\n";
        }
    }
    return 0;
}

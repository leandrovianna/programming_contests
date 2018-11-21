// Codeforces - Phone Numbers - 1060A Div1+Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c8 = 0;
    char ch;
    
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> ch;
        x = ch - '0';
        if (x == 8)
            c8++;
    }

    int ans = 0, other = n - c8;
    while (c8 > 0 && c8 + other >= 11) {
        ans++;
        c8--;
        if (other >= 10)
            other -= 10;
        else {
            c8 -= 10 - other;
            other = 0;
        }
    }

    cout << ans << endl;
    return 0;
}

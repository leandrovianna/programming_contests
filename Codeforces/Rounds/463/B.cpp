// Codeforces - Caisa and Pylons - 463B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    int e = 0, p = 0;
    int ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        
        e = e + p - x;

        if (e < 0) {
            ans += -e;
            e = 0;
        }
        
        p = x;
    }

    cout << ans << endl;
    return 0;
}

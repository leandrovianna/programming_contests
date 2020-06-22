#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;

    int ans = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == 1) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}

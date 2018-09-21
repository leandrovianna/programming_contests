// Codeforces - Cover Points - 1047B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int64_t ans = 0, x, y;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans = max(ans, x + y);
    }
    
    cout << ans << endl;
    return 0;
}

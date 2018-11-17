// Codeforces - Boxes Packing - 1066D Div3
// Second solution - load boxes from back to front
#include <bits/stdc++.h>
using namespace std;

const int N =  2 * 100 * 1000 + 10;
int64_t a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans;
    int64_t k, x;
    int64_t cap = 0;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b = 1;
    cap = 0;
    ans = 0;
    for (int i = n-1; i >= 0; i--) {
        x = a[i];
        if (x + cap <= k) {
            cap += x;
        } else {
            if (b == m)
                break;
            b++;
            cap = x;
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}

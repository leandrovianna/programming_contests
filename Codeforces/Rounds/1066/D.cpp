// Codeforces - Boxes Packing - 1066D Div3
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

    int low = 0, high = n-1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        int b = 1;
        cap = 0;
        for (int i = mid; i < n; i++) {
            x = a[i];
            if (x + cap <= k) {
                cap += x;
            } else {
                b++;
                cap = x;
            }
        }

        if (b <= m) {
            ans = n - mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    cout << ans << endl;
    return 0;
}

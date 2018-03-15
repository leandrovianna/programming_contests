//Codeforces - Sagheer and Nubian Market - 821C Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int n, s;
int64_t base[N], price[N];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> base[i];

    int lo = 1, hi = n, k;
    int64_t ans = 0;
    int ansk = 0;

    while (lo <= hi) {
        k = (lo + hi) / 2;

        for (int i = 0; i < n; i++) {
            price[i] = base[i] + (i+1LL) * k;
        }

        sort(price, price+n);

        int64_t local_ans = 0;
        for (int i = 0; i < k; i++) {
            local_ans += price[i];
        }

        if (local_ans <= s) {
            lo = k+1;
            ans = local_ans;
            ansk = k;
        } else {
            hi = k-1;
        }
    }

    cout << ansk << " " << ans << endl;

    return 0;
}

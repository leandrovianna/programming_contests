// Codeforces - Nirvana - 1143B Div2
#include <bits/stdc++.h>
using namespace std;

int64_t prod_digits(int64_t x) {
    int64_t r = 1;
    while (x > 0) {
        r *= x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    int64_t n, x, prod, ans;

    cin >> n;

    if (n <= 10000) {
        ans = 0;
        for (int64_t i = 1; i <= n; i++) {
            prod = 1;
            x = i;
            while (x > 0) {
                prod *= x % 10;
                x /= 10;
            }

            ans = max(ans, prod);
        }

        cout << ans << "\n";
        return 0;
    }

    int cnt = 0;
    x = n;
    while (x > 0) {
        x /= 10;
        cnt++;
    }

    int64_t y = 0;
    for (int i = 0; i < cnt-3; i++) {
        y = y * 10 + 9;
    }

    ans = pow(9, cnt-3);
    for (int64_t i = 1; i <= 999; i++) {
        x = y + i * pow(10, cnt-3); 
        if (x <= n) {
            prod = pow(9, cnt-3) * prod_digits(i);
            //cout << x << " " << prod << endl;
            ans = max(ans, prod);
        }
    }

    cout << ans << "\n";

    return 0;
}

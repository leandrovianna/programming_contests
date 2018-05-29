// Codeforces - Duff in Love - 588B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;

    cin >> n;

    int64_t ans = 1;

    for (int64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans *= i;
        }

        while (n % i == 0) {
            n /= i;
        }
    }

    if (n > 1)
        ans *= n;

    cout << ans << endl;

    return 0;
}

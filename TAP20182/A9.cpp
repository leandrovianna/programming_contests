// TAP 2018-2 - Desafio - A9
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;

    cin >> n;

    int64_t ans = 0;

    for (int64_t i = (n / 4LL) * 4LL; i <= n; i++) {
        ans ^=  i;
    }

    cout << ans << "\n";
    return 0;
}

// Codeforces - Book Reading - 1213C Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    int64_t n, m;

    cin >> q;

    while (q--) {
        cin >> n >> m;

        int64_t g = n / m;

        int di = m % 10;
        int64_t qtd = 1;
        int64_t sumdigits = di;
        for (int64_t i = m+m; i % 10 != di; i += m) {
            qtd++;
            sumdigits += i % 10;
        }

        int64_t ans = (g / qtd) * sumdigits;

        for (int64_t i = m, k = 0; k < g % qtd; k++, i += m) {
            ans += i % 10;
        }

        cout << ans << "\n";

    }
    return 0;
}

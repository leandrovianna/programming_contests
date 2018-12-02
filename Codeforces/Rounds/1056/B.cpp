// Codeforces - Divide Candies - 1056B
#include <bits/stdc++.h>
using namespace std;

int64_t qtd(int i, int m, int n) {
    return (n - i) / m + (i > 0 ? 1 : 0);
}

int main() {
    int n, m;
    cin >> n >> m;

    int64_t ans = 0;
    for (int i = 0; i < min(m, n+1); i++) {
        for (int j = 0; j < min(n+1, m); j++) {
            if ((i*i+j*j) % m == 0) {
                ans += qtd(i, m, n) * qtd(j, m, n);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

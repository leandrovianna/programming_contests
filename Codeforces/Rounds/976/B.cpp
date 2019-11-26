// Codeforces - Lara Croft and the New Game - 976B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, m, k;
    cin >> n >> m >> k;

    if (k < n) {
        cout << k+1 << " 1\n";
    } else {
        k -= n-1;
        int64_t i = n - (k-1) / (m-1);
        int64_t j = (k-1) % (m-1);
        if (i % 2 != 0)
            j = m - j;
        else
            j += 2;

        cout << i << " " << j << "\n";
    }

    return 0;
}

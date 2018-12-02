#include <bits/stdc++.h>
using namespace std;

int64_t teto(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

int main() {
    int64_t n, m, k, l;

    cin >> n >> m >> k >> l;

    if (m > n || l + k > n) {
        cout << "-1" << endl;
    } else {
        int64_t x = teto(l + k, m);
        if (x * m <= n)
            cout << x << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}

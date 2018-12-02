//AtCoder - Flip, Flip and Flip - Regular 091
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, m;

    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 1 || m == 1) {
        cout << (n * m) - 2 << endl;
    } else {
        cout << (n * m) - (4 + (n - 2) * 2 + (m - 2) * 2);
    }
    return 0;
}

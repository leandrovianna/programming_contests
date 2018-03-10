#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int a, b, n;

    cin >> n >> a >> b;

    int r = 0, m = n;
    while (n > 1) {
        n /= 2;

        if ((a <= n && n < b) ||
                (b <= n && n < a)) {
            break;
        }

        if (a > n && b > n) {
            a -= n;
            b -= n;
        }

        r++;
    }

    if (r == 0) {
        cout << "Final!" << endl;
    } else {
        cout << static_cast<int>(log2(m)) - r << endl;
    }

    return 0;
}

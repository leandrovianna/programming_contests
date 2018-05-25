#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t x;
    int k;

    cin >> x >> k;

    for (int i = 0; i < k; i++) {
        if (x % 10 == 0) {
            x /= 10;
        } else {
            x--;
        }
    }

    cout << x << endl;

    return 0;
}

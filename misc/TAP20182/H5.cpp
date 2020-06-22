// TAP 2018/2 - Melancias
#include <bits/stdc++.h>
using namespace std;

int main() {
    double v1, v2;

    cin >> v1 >> v2;

    int ans = 0;
    int64_t acc = 0;
    for (int i = 1; i <= 1000000; i++) {
        acc += (i * (i+1)) / 2;
        if (acc * v1 > v2) {
            break;
        }
        ans = i;
    }

    cout << ans << endl;
    return 0;
}

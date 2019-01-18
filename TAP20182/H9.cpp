// TAP 2018/2 - Terrenos - H9
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;

    cin >> n;

    bool ans = false;

    for (int64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans = true;
            if (i * i != n) {
                ans = false;
                break;
            }
            for (int64_t j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    ans = false;
                    break;
                }
            }

            break;
        }
    }

    cout << (ans ? "S" : "N") << endl;
    return 0;
}

// Live Archive - Irrational Roots - 7178 - SEERC 2015
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 10;
    int64_t c[N], _c[N];
    int n;

    while (cin >> n) {
        for (int i = n-1; i >= 0; i--) {
            cin >> c[i];
        }
        c[n] = 1;

        int answer = n;

        for (int x = -10; x <= 10; x++) {
            memcpy(_c, c, sizeof(c));

            for (int i = 0; i <= n; i++) {
                int64_t k = 1, v = 0;
                for (int j = i; j <= n; j++) {
                    v += k * _c[j];
                    k *= x;
                }

                // x is a root
                if (v == 0) {
                    answer--;

                    // synthetic division
                    // to verify whether x is root
                    // with a largest multiplicity
                    for (int j = n-1; j > i; j--) {
                        _c[j] += _c[j+1] * x;
                    }
                } else {
                    break;
                }
            }
        }

        cout << answer << "\n";
    }
    return 0;
}

// TAP 2018/2 - Nested Ring Stacking
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int r, a[N], mark[N];

    cin >> r;
    for (int i = 0; i < r; i++) {
        cin >> a[i];
        mark[i] = 0;
    }

    for (int i = 0; i < r; i++) {
        if (mark[i] == 0) {
            for (int j = 0; j < r; j++) {
                if (i == j)
                    continue;

            }
        }
    }
    return 0;
}

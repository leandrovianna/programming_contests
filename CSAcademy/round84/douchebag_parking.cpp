// CS Academy - Douchebag Parking - Round 84
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;

    int acc = 0;
    int lowidx = -1;
    int li = -1;

    cin >> n >> w;

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;

        if (lowidx == -1) {
            if (x == 1) {
                if (li == -1)
                    li = i+1;
                acc += y;

                if (acc >= w) {
                    lowidx = li;
                }
            } else {
                li = -1;
                acc = 0;
            }
        }
    }

    cout << lowidx << endl;
    return 0;
}

// Codeforces - Snowball - 1099A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h;
    int u1, d1, u2, d2;

    cin >> w >> h;

    cin >> u1 >> d1;
    cin >> u2 >> d2;


    while (h > 0) {
        w += h;
        if (d1 == h)
            w -= u1;

        if (d2 == h)
            w -= u2;

        w = max(w, 0);

        h--;
    }

    cout << w << endl;
    return 0;
}

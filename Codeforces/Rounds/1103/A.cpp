// Codeforces - Grid Game - 1103A - Div1
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    cin >> s;

    int x1 = 1, y1 = 1, x2 = 3, y2 = 1;

    for (const auto &ch : s) {
        if (ch == '0') {
            cout << x1 << " " << y1 << "\n";
            y1++;
            if (y1 == 5)
                y1 = 1;
        } else {
            cout << x2 << " " << y2 << "\n";
            y2 += 2;
            if (y2 == 5)
                y2 = 1;
        }
    }
    return 0;
}

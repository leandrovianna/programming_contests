// Codeforces - New Year and the Christmas Ornament - 1091A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int y, b, r;

    cin >> y >> b >> r;

    for (int i = y; i >= 1; i--) {
        if (b >= i+1 && r >= i+2) {
            cout << 3*i+3 << "\n";
            break;
        }
    }
    return 0;
}

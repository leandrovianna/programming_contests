// Codeforces - Little C Loves 3 I - 1047A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;

    cin >> n;

    int64_t x, y, z;
    x = 1;
    y = 1;
    z = n-2;

    if (z % 3 == 0) {
        y++;
        z--;
    } 

    cout << x << " " << y << " " << z << endl;

    return 0;
}

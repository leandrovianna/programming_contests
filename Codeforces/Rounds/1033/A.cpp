#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int ax, ay, bx, by, cx, cy;
    cin >> n;

    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    if ((bx < ax) == (cx < ax) && (by < ay) == (cy < ay)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

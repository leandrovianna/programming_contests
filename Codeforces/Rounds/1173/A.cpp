// Codeforces - Nauuo and Votes - 1173A
#include <bits/stdc++.h>
using namespace std;

int sig(int x) {
    if (x < 0)
        return -1;
    else if (x > 0)
        return 1;
    else
        return 0;
}

int main() {
    int x, y, z;

    cin >> x >> y >> z;

    int r1 = x - y + z, r2 = x - y - z;

    if (sig(r1) != sig(r2)) {
        cout << "?\n";
    } else {
        int s = sig(r1);
        if (s == -1) {
            cout << "-\n";
        } else if (s == 1) {
            cout << "+\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}

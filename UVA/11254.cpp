//UVA - Consecutive Integers - 11254
#include <bits/stdc++.h>
using namespace std;

bool check(int r, int n, int &a) {
    if ((2 * n - r * r + r) % (2 * r) == 0) {
        a = (2 * n - r * r + r) / (2 * r);
        return true;
    }
    
    return false;
}

int main() {
    int n, a;

    while (cin >> n && n != -1) {
        for (int r = sqrt(2 * n); r >= 1; r--) {
            if (check(r, n, a)) {
                cout << n << " = "
                    << a << " + ... + " << a + r - 1 << "\n";
                break;
            }
        }
    }
    return 0;
}

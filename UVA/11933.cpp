// UVA - 11933 - Splitting Numbers
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while (cin >> n, n) {
        int a = 0, b = 0;
        bool change = true;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                if (change)
                    a |= (1 << i);
                else
                    b |= (1 << i);
                change = !change;
            }
        }

        cout << a << " " << b << "\n";
    }
    return 0;
}

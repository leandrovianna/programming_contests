#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
    bool ch = false;
    for (int i = 0; i <= 30; i++) {
        if ((1 << i) & x) {
            if (ch) {
                return false;
            }

            ch = true;
        } else {
            ch = false;
        }
    }

    return true;
}

int main() {
    int k;

    cin >> k;
    int x = 1;
    for (int i = 0; i < k; i++) {
        while (check(x) == false) {
            x++;
        }
        x++;
    }

    cout << x-1 << endl;
    return 0;
}

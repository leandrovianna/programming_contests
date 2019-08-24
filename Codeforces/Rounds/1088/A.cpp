// Codeforces - Ehab and another construction problem - 1088A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;

    cin >> x;

    for (int a = 1; a <= x; a++) {
        for (int b = 1; b <= x; b++) {
            if (a % b == 0 && a * b > x && a / b < x) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }

    cout << "-1" << endl;
    return 0;
}

// Codeforces - In Search of an Easy Problem - 1058A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;

    cin >> n;

    bool hard = false;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1)
            hard = true;
    }

    cout << (hard ? "HARD" : "EASY") << endl;
    return 0;
}

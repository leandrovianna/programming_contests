// TAP 2018/2 - Log Bacterias
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double a = 0, b = 0;

    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a += log10(x);
    }

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        b += log10(x);
    }

    cout << (a > b ? "A" : "B") << endl;
    return 0;
}

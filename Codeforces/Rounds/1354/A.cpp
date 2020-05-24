// Codeforces - Alarm Clock - 1354A
#include <bits/stdc++.h>
using namespace std;

int64_t ceilint(int64_t num, int64_t den) {
    return (num + den - 1) / den;
}

int main() {
    int t;
    int64_t a, b, c, d;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c >> d;

        if (a <= b)
            cout << b << "\n";
        else if (c > d)
            cout << b + c * ceilint(a - b, c - d) << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}

// Facebook Hacker Cup 2018 - Qualification
// Interception - 25 points
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a;

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n;
        for (int i = 0; i < n+1; i++) {
            cin >> a;
        }

        cout << "Case #" << ti << ": ";
        if (n % 2 == 0) {
            cout << "0\n";
        } else {
            cout << "1\n0.0\n";
        }
    }
    return 0;
}

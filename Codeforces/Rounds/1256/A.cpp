// Codeforces - Payment Without Change
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    int64_t a, b, n, s;

    cin >> q;
    while (q--) {
        cin >> a >> b >> n >> s;
        if (s / n <= a && s % n <= b) {
            cout << "YES\n";
        } else if (s / n > a && s - a * n <= b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

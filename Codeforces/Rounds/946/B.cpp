// Codeforces - Weird Subtraction Process - 946B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t a, b;

    cin >> a >> b;

    while (a != 0 && b != 0) {
        if (a >= 2 * b) {
            a = a % (2 * b);
        } else if (b >= 2 * a) {
            b = b % (2 * a);
        } else {
            break;
        }
    }

    cout << a << " " << b << "\n";
    return 0;
}

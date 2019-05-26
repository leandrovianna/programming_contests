// Codeforces - Circle Metro - 1169A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, x, b, y;

    cin >> n >> a >> x >> b >> y;

    bool answer = false;

    while (a != x && b != y) {
        if (a < n)
            a++;
        else
            a = 1;

        if (b > 1)
            b--;
        else
            b = n;

        if (a == b) {
            answer = true;
            break;
        }
    }

    cout << (answer ? "YES" : "NO") << "\n";
    return 0;
}

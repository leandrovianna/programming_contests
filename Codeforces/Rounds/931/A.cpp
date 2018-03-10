#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    int ans = 0;

    int y = 1;
    bool x = true;
    while (a != b) {
        ans += y;

        if (x) {
            a++;
        } else {
            b--;
            y++;
        }

        x = !x;
    }

    cout << ans << endl;
    return 0;
}

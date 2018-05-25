#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, y;
    string cmd;

    int64_t x = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd >> y;
        if (cmd == "add" && y > 0) {
            x += y;
        }

        if (cmd == "set" && y > x) {
            x = y;
        }
    }

    cout << x << endl;
    return 0;
}

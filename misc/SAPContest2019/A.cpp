#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    int c = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x <= 0)
            c++;
    }

    if (c >= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

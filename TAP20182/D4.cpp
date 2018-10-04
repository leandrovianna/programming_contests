// TAP 2018/2 - Desvendando Monty Hall
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x != 1)
            ans++;
    }

    cout << ans << endl;
    return 0;
}

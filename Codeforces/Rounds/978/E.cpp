// Codeforces - Bus Video System - 978E
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int64_t w, x;

    cin >> n >> w;

    int64_t e = 0, st = w, en = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;

        e += x;

        st = min(st, e);
        en = max(en, e);
    }

    if (st < 0)
        st = -st;
    else
        st = 0;

    int64_t ans = (w - en) - st + 1;
    cout << max(int64_t{0}, ans) << endl;
    return 0;
}

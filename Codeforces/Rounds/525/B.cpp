#include <bits/stdc++.h>
using namespace std;

const int L = 2 * 1000 * 100 + 10;
int mark[L];

int main() {
    int m;
    string t;

    cin >> t >> m;
    for (int i = 0, k, sz = t.size(); i < m; i++) {
        cin >> k;
        mark[k]++;
        int r = sz - k + 1;
        mark[(k + r) / 2 + 1]--;
    }

    for (int i = 1, k = 0, sz = t.size(); i <= sz; i++) {
        k += mark[i];
        if (k & 1)
            swap(t[i-1], t[sz-i]);
    }

    cout << t << endl;

    return 0;
}

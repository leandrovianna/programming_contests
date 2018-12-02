#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string s, t;
    int n;

    cin >> k >> s >> t;
    n = s.size();

    int same = 0, diff = 0;
    for (int i = 0, sz = s.size(); i < sz; i++) {
        if (s[i] == t[i])
            same++;
        else
            diff++;
    }

    cout << (same < k ? same + min(diff, n - k) : k + diff) << endl;
    return 0;
}

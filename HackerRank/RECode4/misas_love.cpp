// Hackerrank - RECode 4.0 - Misa's Love - 1st
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    int n;
    cin >> s;
    n = s.size();
    multiset<string> substrs;

    for (int i = 0; i < n; i++) {
        t = "";
        for (int j = i; j < n; j++) {
            t += s[j];
            substrs.insert(t);
        }
    }

    t = "";
    int ans = 1;
    for (int i = 0; i < n; i++) {
        t += s[i];
        ans = max(ans, (int) substrs.count(t));
    }

    cout << ans << endl;
    return 0;
}

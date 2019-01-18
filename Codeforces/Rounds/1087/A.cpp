// Codeforces - Right-Left Cipher - 1087A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;
    cin >> t;
    int n = t.size();
    string s = t;
    int p1 = 0, p2 = n-1;

    while (n > 0) {
        if (n & 1) {
            s[n-1] = t[p1];
            p1++;
        } else {
            s[n-1] = t[p2];
            p2--;
        }
        n--;
    }

    cout << s << endl;
    return 0;
}

// Codeforces - Repeating Cipher - 1095A Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    string t;

    for (int i = 0, j = 1; i < n; i += j, j++) {
        t += s[i];
    }

    cout << t << endl;
    return 0;
}

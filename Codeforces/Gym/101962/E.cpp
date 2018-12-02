#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
int pref[N];

int main() {
    string s;
    cin >> s;
    int sz = s.size();

    if (sz == 1) {
        cout << (s[0] == '1' ? "NO" : "YES") << endl;
        return 0;
    }

    int i = 0;
    for (const auto &ch : s) {
        pref[i] = (ch == '0' ? 0 : 1) ^ (i == 0 ? 0 : pref[i-1]);
        i++;
    }

    if (pref[sz-2] != s[sz-1] - '0') {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = sz-1; i >= 0; i--) {
        int j = pref[i-1];
        int k = pref[sz-1] ^ pref[i];

        if ((j != k && s[i] == '0') || (j == k && s[i] == '1')) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

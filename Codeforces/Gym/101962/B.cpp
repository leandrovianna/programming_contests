#include <bits/stdc++.h>
using namespace std;

int main() {
    const int E = 5;
    string s, t;
    char match[E];

    cin >> s >> t;

    int ans = 0;

    for (int i = 0, sz = s.size(), sz2 = t.size(); i < sz-sz2+1; i++) {
        memset(match, 0, sizeof(match));
        bool wrong = false;
        for (int j = 0; j < sz2; j++) {
            if (match[t[j] - '0'] == 0) {
                match[t[j] - '0'] = s[i + j];
            } else {
                if (match[t[j] - '0'] != s[i + j]) {
                    wrong = true;
                    break;
                }
            }
        }

        if (!wrong) {
            ans++;
            continue;
        }

        memset(match, 0, sizeof(match));
        wrong = false;
        for (int j = 0; j < sz2; j++) {
            if (match[t[j] - '0'] == 0) {
                match[t[j] - '0'] = s[i + sz2 - 1 - j];
            } else {
                if (match[t[j] - '0'] != s[i + sz2 - 1 - j]) {
                    wrong = true;
                    break;
                }
            }
        }

        if (!wrong) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

// Codeforces - Hate "A" - 1146B - Forethought Future Cup - Elimination Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;

    cin >> s;
    n = s.size();

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            last = i;
    }

    string t = ""; 
    int z = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a')
            t += s[i];

        if (i == last)
            z = t.size();
    }

    int m = t.size();

    if (m % 2 == 0 && z <= m / 2 && t.substr(0, m / 2) == t.substr(m / 2)) {
        for (int i = 0, j = 0; i <= last || j < m / 2; i++) {
            cout << s[i];

            if (s[i] != 'a') {
                j++;
            }
        }
        cout << "\n";
    } else {
        cout << ":(\n";
    }

    return 0;
}

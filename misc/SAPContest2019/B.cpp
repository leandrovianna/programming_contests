#include <bits/stdc++.h>
using namespace std;

map<string, string> f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    string s, t;
    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        f[s] = t;
    }

    s = "A";
    string tmp = "";

    for (int i = 0; i < n; i++) {
        t = ""; // new string
        tmp = ""; // temporary
        tmp += s[0];

        for (int j = 1, k = s.size(); j < k; j++) {
            if (s[j] == s[j-1])
                tmp += s[j]; // add to tmp
            else {
                t += f[tmp]; // add new piece
                tmp = ""; // start new tmp
                tmp += s[j];
            }
        }
        t += f[tmp]; // add new piece

        s = t;
    }

    int ca = 0, cb = 0;
    for (const auto &ch : s) {
        if (ch == 'A')
            ca++;
        else if (ch == 'B')
            cb++;
    }

    cout << ca << " " << cb << "\n";
    return 0;
}

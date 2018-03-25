//Codeforces - Tritonic Iridescence - 957A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s;

    cin >> n >> s;

    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] != '?' && s[i] == s[i-1]) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] == '?' && s[i] == s[i-1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    if (s[0] == '?') {
        cout << "Yes" << endl;
        return 0;
    }

    if (s[s.size()-1] == '?') {
        cout << "Yes" << endl;
        return 0;
    }

    int q = 0;
    set<string> ss;
    for (size_t i = 1; i < s.size()-1; i++) {
        if (s[i] == '?') {
            if (s[i-1] == s[i+1]) {
                cout << "Yes" << endl;
                return 0;
            }
            // else if (ss.count(s[i-1] + "" + s[i+1]) && ss.count(s[i+1] + "" + s[i-1])) {
            //     ss.insert(s[i-1] + "" + s[i+1]);
            //     ss.insert(s[i+1] + "" + s[i-1]);
            //     q += 1;
            //     cout << s[i-1] << s[i] << s[i+1] << endl;
            // }
        }
    }

    if (q < 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}

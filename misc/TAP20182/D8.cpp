// TAP 2018/2 - Database of Clients - D8
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    set<string> emails;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        t = "";

        for (size_t i = 0; i < s.find('@'); i++) {
            if (s[i] == '+')
                break;
            if (s[i] != '.')
                t += s[i];
        }

        t += s.substr(s.find('@'));
        emails.insert(t);
    }

    cout << emails.size() << endl;
    return 0;
}

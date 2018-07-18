#include <bits/stdc++.h>
using namespace std;

bool con(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'u':
        case 'o':
        case 'A':
        case 'E':
        case 'I':
        case 'U':
        case 'O':
            return false;
    }

    return true;
}

int main() {
    string s;

    cin >> s;

    int sz = s.size();

    for (int i = 1; i < sz; i++) {
        if (s[i-1] != 'n' && con(s[i-1]) && con(s[i])) {
            cout << "NO\n";
            return 0;
        }
    }

    if (s[sz-1] != 'n' && con(s[sz-1])) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    return 0;
}

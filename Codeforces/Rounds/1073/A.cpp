// Codeforces - Diverse Substring - 1073A Edu Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            cout << "YES\n";
            cout << s[i-1] << s[i] << endl;
            return 0;
        }
    }

    for (int i = 2; i < n; i++) {
        if (s[i] != s[i-2]) {
            cout << "YES\n";
            cout << s[i-2] << s[i-1] << s[i] << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}

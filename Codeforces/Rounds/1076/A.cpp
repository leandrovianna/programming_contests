#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;

    cin >> n;
    cin >> s;

    for (int i = 0; i < n-1; i++) {
        if (s[i] > s[i+1]) {
            cout << s.substr(0, i) + s.substr(i+1) << endl;
            return 0;
        }
    }

    cout << s.substr(0, n-1) << endl;

    return 0;
}

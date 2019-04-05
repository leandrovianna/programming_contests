// Codeforces - Diverse Strings - 1144A Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;

    cin >> n;

    for (int i = 0, j, m; i < n; i++) {
        cin >> s;

        sort(s.begin(), s.end());
        
        for (j = 1, m = s.size(); j < m; j++) {
            if (s[j] != s[j-1] + 1) {
                cout << "No\n";
                break;
            }
        }

        if (j == m) {
            cout << "Yes\n";
        }
    }
    return 0;
}

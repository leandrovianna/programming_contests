// Codejam 2019 - Qualification Round - Foregone Solution
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string n, s;

    cin >> t;
    
    for (int ti = 1; ti <= t; ti++) {
        cin >> n;
        s = string(n.size(), '0');

        for (size_t i = 0; i < n.size(); i++) {
            if (n[i] == '4') {
                s[i] = '2';
                n[i] = '2';
            } else {
                s[i] = '0';
            }
        }

        cout << "Case #" << ti << ": ";
        cout << n << " ";
        for (size_t i = 0, firstpositive = 0; i < s.size(); i++) {
            if (!firstpositive && s[i] != '0') {
                firstpositive = 1;
            }
            
            if (firstpositive) {
                cout << s[i];
            }
        }

        cout << "\n";
    }
    return 0;
}

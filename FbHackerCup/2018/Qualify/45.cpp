// Facebook Hacker Cup - Qualification
// Ethan Searches for a String
#include <bits/stdc++.h>
using namespace std;

bool test(string a, int sz) {
    int i = 0, j = 0;
    string b = a.substr(0, sz) + a;
    
    while (true) {
        if (i == (int) a.size()) {
            return true;
        }

        if (j == (int) b.size()) {
            return false;
        }

        if (a[i] == b[j]) {
            i++;
            j++;
            continue;
        }

        if (i == 0) {
            j++;
            continue;
        }

        i = 0;
    }
}

int main() {
    int t;
    string a;
    
    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> a;

        bool found = false;
        cout << "Case #" << ti << ": ";
        for (int i = 1; i < (int) a.size(); i++) {
            if (test(a, i) == false) {
                cout << a.substr(0, i) << a << "\n";
                found = true;
                break;
            }
        }

        if (found == false)
            cout << "Impossible\n";
    }

    return 0;
}

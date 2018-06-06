// Codeforces - Password - 126B Div1
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    vector<int> pi(s.size());

    pi[0] = 0;
    for (int i = 1, j; i < (int) s.size(); i++) {
        j = pi[i-1];
        while (j > 0 && s[j] != s[i])
            j = pi[j-1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

int main() {
    string s;

    cin >> s;

    vector<int> pi = prefix_function(s);

    int ans = pi.back();

    if (ans != 0) {
        for (int i = 1; i < (int) s.size()-1; i++) {
            if (pi[i] == ans) {
                cout << s.substr(s.size()-ans, ans) << endl;
                return 0;
            }
        }

        ans = pi[ans-1];
    }

    cout << (ans == 0 ? "Just a legend" : s.substr(0, ans)) << endl;

    return 0;
}

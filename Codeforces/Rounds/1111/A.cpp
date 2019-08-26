// Codeforces - Superhero Transformation - 1111A Div2
#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i'
        || ch == 'o' || ch == 'u';
}

int main() {
    string s, t;

    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "No\n";
    } else {
        for (size_t i = 0; i < s.size(); i++) {
            if (is_vowel(s[i]) != is_vowel(t[i])) {
                cout << "No\n";
                return 0;
            }
        }

        cout << "Yes\n";
    }
    return 0;
}

// Codeforces - Letters Rearranging - 1093B
#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    string s;

    cin >> t;

    while (t--) {
        cin >> s;

        if (palindrome(s)) {
            bool diff = false;
            for (size_t i = 1; i < s.size(); i++) {
                if (s[i] != s[i-1]) {
                    swap(s[i], s[i-1]);
                    diff = true;
                    break;
                }
            }

            if (diff) {
                cout << s << "\n";
            } else {
                cout << "-1\n";
            }
        } else {
            cout << s << "\n";
        }
    }
    return 0;
}

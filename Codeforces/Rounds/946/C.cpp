// Codeforces - String Transformation - 946C
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;

    char letter = 'a';
    for (int i = 0, n = s.size(); i < n; i++) {
        if (letter == 'z'+1)
            break;

        if (s[i] <= letter) {
            s[i] = letter;
            letter++;
        }
    }

    cout << (letter == 'z'+1 ? s : "-1") << "\n";

    return 0;
}

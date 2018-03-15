//Codeforces - Word - 59A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int countUpper = 0,
        countLower = 0;

    for (const auto &c : s) {
        if (isupper(c))
            countUpper++;
        else
            countLower++;
    }

    if (countUpper > countLower) {
        for (size_t i = 0; i < s.size(); i++)
            s[i] = toupper(s[i]);
    } else {
        for (size_t i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);
    }

    cout << s << endl;

    return 0;
}

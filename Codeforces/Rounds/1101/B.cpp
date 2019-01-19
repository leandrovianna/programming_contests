// Codeforces - Accordion - 1010B - Edu Round 58
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int mark1 = -1, mark2 = -1, mark3 = -1,
        mark4 = -1;

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
            mark1 = i;
            break;
        }
    }

    if (mark1 == -1) {
        cout << "-1\n";
        return 0;
    }

    for (size_t i = mark1+1; i < s.size(); i++) {
        if (s[i] == ':') {
            mark2 = i;
            break;
        }
    }

    if (mark2 == -1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = s.size()-1; i > mark2; i--) {
        if (s[i] == ']') {
            mark4 = i;
            break;
        }
    }

    if (mark4 == -1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = mark4-1; i > mark2; i--) {
        if (s[i] == ':') {
            mark3 = i;
            break;
        }
    }

    if (mark3 == -1) {
        cout << "-1\n";
        return 0;
    }

    int keep = 0;
    for (int i = mark2+1; i < mark3; i++) {
        if (s[i] == '|')
            keep++;
    }

    int ans = 4 + keep;

    cout << ans << "\n";
    return 0;
}

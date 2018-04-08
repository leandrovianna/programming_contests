//Codeforces - Vitaly and Strings - 518A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;

    cin >> s >> t;

    // passa a s para a proxima string
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] < 'z') {
            s[i]++;
            break;
        } else {
            s[i] = 'a';
        }
    }

    if (s == t) {
        cout << "No such string" << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}

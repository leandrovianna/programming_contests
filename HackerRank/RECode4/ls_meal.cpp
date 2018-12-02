// Hackerrank - L's Meal - RECode 4.0 - 2nd
#include <bits/stdc++.h>
using namespace std;

int64_t calc(string &s) {
    int64_t ans = 0, count_c = 0, count_p = 0;

    for (int i = 0, n = s.size(); i < n; i++) {
        if (s[i] == 'c') {
            count_c++;
        } else {
            ans += count_c;
        }
    }

    for (int n = s.size(), i = n-1; i >= 0; i--) {
        if (s[i] == 'p') {
            count_p++;
        } else {
            ans += count_p;
        }
    }

    return ans;
}

int main() {
    string s;
    int p_pos = -1, c_pos = -1;
    cin >> s;

    for (int i = 0, n = s.size(); i < n; i++) {
        if (s[i] == 'p') {
            p_pos = i;
        }
    }

    for (int i = 0, n = s.size(); i < n; i++) {
        if (s[i] == 'c') {
            c_pos = i;
            break;
        }
    }

    if (p_pos == -1 || c_pos == -1) {
        cout << "0" << endl;
    } else {
        int64_t ans = calc(s);
        swap(s[c_pos], s[p_pos]);
        cout << min(ans, calc(s)) << endl;
    }
    return 0;
}

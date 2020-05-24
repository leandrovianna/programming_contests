#include <bits/stdc++.h>
using namespace std;

string solve(string &s, int l, int r, int depth = 0) {
    if (l > r)
        return "";

    string ans = "";

    int f = -1;
    for (int i = l; i <= r; i++) {
        int d = s[i] - '0';

        if (f == -1) {
            if (d > depth) {
                f = i;
            } else {
                ans += s[i];
            }
        } else {
            if (d <= depth) {
                ans += "(" + solve(s, f, i-1, depth+1) + ")";
                f = -1;
                ans += s[i];
            }
        }
    }

    if (f != -1) {
        ans += "(" + solve(s, f, r, depth+1) + ")";
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string s;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> s;

        cout << "Case #" << ti << ": "
            << solve(s, 0, s.size() - 1) << "\n";
    }
    return 0;
}

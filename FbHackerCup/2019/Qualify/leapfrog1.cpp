#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> t;

    string s;

    for (int ti = 1; ti <= t; ti++) {
        cin >> s;

        int ndots = 0, nbeta = 0;
        for (const auto &ch : s) {
            if (ch == '.')
                ndots++;
            else if (ch == 'B')
                nbeta++;
        }

        cout << "Case #" << ti << ": ";
        if (0 < ndots && ndots <= nbeta) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}

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

        int ndot = 0, nbeta = 0;
        for (const auto &ch : s) {
            if (ch == '.') {
                ndot++;
            } else if (ch == 'B') {
                nbeta++;
            }
        }

        cout << "Case #" << ti << ": ";
        if (ndot > 0 && (ndot <= nbeta || nbeta > 1)) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}

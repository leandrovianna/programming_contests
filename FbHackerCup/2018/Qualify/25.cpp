// Facebook Hacker Cup 2018 - Qualification Round - Tourist - 25 points
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, k, n;
    int64_t v;

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n >> k >> v;

        string str;
        set<pair<int, string> > output;
        int64_t inc = (v - 1) * (n - k);
        for (int i = 0; i < n; i++) {
            cin >> str;

            int pos = (i + inc) % n;

            if (pos < k) {
                output.insert({i, str});
            }
        }

        cout << "Case #" << ti << ": ";
        for (auto it = output.begin(); it != output.end(); it++) {
            cout << it->second;

            if (next(it) == output.end()) cout << "\n";
            else cout << " ";
        }
    }
    return 0;
}

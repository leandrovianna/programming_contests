// Codeforces - Vitamins - 1042B Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
map<string, int64_t> best;

int main() {
    int n;
    string s;
    const int64_t INF = 1000 * 1000 * 1000LL * 1000;
    int64_t c;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c >> s;
        sort(s.begin(), s.end());
        if (best.count(s))
            best[s] = min(best[s], c);
        else
            best[s] = c;
    }

    int64_t ans = INF;

    for (const auto &p1 : best) {
        for (const auto &p2 : best) {
            if (p1.first == p2.first)
                continue;

            s = p1.first + p2.first;
            if (s.find("A") != string::npos
                 && s.find("B") != string::npos
                 && s.find("C") != string::npos) {
                ans = min(ans, p1.second + p2.second);
            }
        }
    }

    if (best.count("ABC"))
        ans = min(ans, best["ABC"]);

    if (best.count("A") && best.count("B") && best.count("C"))
        ans = min(ans, best["A"] + best["B"] + best["C"]);

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}

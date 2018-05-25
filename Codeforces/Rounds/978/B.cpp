// Codeforces - Filename - 978B Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    vector<int> seq;

    char prev = 0;
    int sq = 0;
    for (const auto &c : s) {
        if (c == 'x') {
            if (prev == c) {
                sq++;
            } else {
                sq = 1;
            }
        } else if (sq > 0) {
            seq.push_back(sq);
            sq = 0;
        }

        prev = c;
    }

    seq.push_back(sq);

    int ans = 0;
    for (const auto &x : seq) {
        //cout << "*" << x << endl;
        if (x >= 3) {
            ans += x-2;
        }
    }

    cout << ans << endl;

    return 0;
}

// Codeforces - The Fair Nut and String - 1084C Div2
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int64_t>> pre;

int64_t exp(int64_t base, int64_t e, int64_t mod) {
    int64_t ans = 1;
    while (e) {
        if (e & 1) {
            ans = (base * ans) % mod;
        }

        base = (base * base) % mod;
        e >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t, s;

    cin >> t;
    s = "";
    for (const auto &ch : t) {
        if (ch == 'a' || ch == 'b') {
            s += ch;
        }
    }

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            if (pre.size() > 0 && pre.back().first == (int) i-1) {
                pre.back().first = i;
                pre.back().second++;
            } else {
                pre.push_back({i, 1});
            }
        }
    }

    const int64_t mod = 1000000007;
    int64_t ans = 0;
    for (size_t i = 0; i < pre.size(); i++) {
        ans = (ans + pre[i].second + (pre[i].second * ans) % mod) % mod;
    }

    cout << ans << "\n";

    return 0;
}

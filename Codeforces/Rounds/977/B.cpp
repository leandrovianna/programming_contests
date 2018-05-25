#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    map<string, int> cnt;

    cin >> n >> s;

    for (int i = 0; i < n-1; i++) {
        cnt[s.substr(i, 2)]++;
    }

    int64_t ma = 0;
    string ans;
    for (const auto &p : cnt) {
        if (ma < p.second) {
            ma = p.second;
            ans = p.first;
        }
    }

    cout << ans << endl;
    return 0;
}

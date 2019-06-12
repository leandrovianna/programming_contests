// Codeforces - Games on a CD - 727E
#include <bits/stdc++.h>
using namespace std;

const int N = 2001000;
struct Hash {
    uint64_t h[N], ppow[N], p, mod;
    Hash() : Hash(33, 1000000007) {
    }

    Hash(uint64_t p, uint64_t mod) : p(p), mod(mod) {
        ppow[0] = 1;
        for (int i = 1; i < N; i++) {
            ppow[i] = (ppow[i-1] * p) % mod;
        }
    }

    void init(string &s) {
        h[0] = 5369ULL;
        for (size_t i = 0; i < s.size(); i++) {
            h[i+1] = (h[i] * p + s[i]) % mod;
        }
    }

    uint64_t get_hash(int i, int j) {
        return (h[j+1] - (h[i] * ppow[j-i+1]) % mod + mod) % mod;
    }
} h, h2, h3(73, 1000000009), h4(73, 1000000009);

map<pair<uint64_t, uint64_t>, int> names;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    s += s;
    h.init(s);
    h4.init(s);

    int g;

    cin >> g;
    for (int i = 0; i < g; i++) {
        cin >> s;
        h2.init(s);
        h3.init(s);
        int l = s.size();
        pair<uint64_t, uint64_t> v = {h2.get_hash(0, l-1), h3.get_hash(0, l-1)};
        names[v] = i+1;
    }

    int m = n * k;
    for (int i = 0; i < k; i++) {
        pair<uint64_t, uint64_t> v = {h.get_hash(i, i+k-1), h4.get_hash(i, i+k-1)};
        if (names.find(v) == names.end()) {
            continue;
        }

        set<int> cds;
        vector<int> ans;
        cds.insert(names[v]);
        ans.push_back(names[v]);

        for (int j = i+k; j < i+m; j += k) {
            v = {h.get_hash(j, j+k-1), h4.get_hash(j, j+k-1)};
            if (names.find(v) != names.end()) {
                cds.insert(names[v]);
                ans.push_back(names[v]);
            } else {
                break;
            }
        }

        if ((int) cds.size() == n) {
            cout << "YES\n";

            for (const auto &idx : ans) {
                cout << idx << " ";
            }
            cout << "\n";

            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

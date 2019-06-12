// Spoj - Ada and Spring Cleaning - ADACLEAN
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

struct Hash {
    uint64_t h[N], ppow[N], p, mod;

    Hash(uint64_t p, uint64_t mod) : p(p), mod(mod) {
        ppow[0] = 1;
        for (int i = 1; i < N; i++) {
            ppow[i] = (ppow[i-1] * p) % mod;
        }
    }

    void init(string &s) {
        h[0] = 5389LL;
        for (size_t i = 0; i < s.size(); i++) {
            h[i+1] = (h[i] * p + s[i]) % mod;
        }
    }

    uint64_t get_hash(int i, int j) {
        return (h[j+1] - (h[i] * ppow[j-i+1]) % mod + mod) % mod;
    }
} h(33, 1000000007), h2(71, 1000000009);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    int n, k;
    string s;

    cin >> t;

    while (t--) {
        cin >> n >> k;
        cin >> s;
        h.init(s);
        h2.init(s);

        set<pair<uint64_t, uint64_t>> ss;
        for (int i = 0; i <= n-k; i++) {
            ss.insert(
                    {h.get_hash(i, i+k-1),
                    h2.get_hash(i, i+k-1)});
        }

        cout << ss.size() << "\n";
    }

    return 0;
}

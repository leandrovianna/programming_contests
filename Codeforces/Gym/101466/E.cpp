// Codeforces Gym - Text Editor - 101466E
// solution with Double Hash
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

struct Hash {
    uint64_t p, mod, ppow[N], ppow2[N], p2, mod2;
    pair<uint64_t, uint64_t> h[N];

    Hash() : p(33), mod(1000000007), p2(73), mod2(1000000009) {
        ppow[0] = 1;
        ppow2[0] = 1;
        for (int i = 1; i < N; i++) {
            ppow[i] = (ppow[i-1] * p) % mod;
            ppow2[i] = (ppow2[i-1] * p2) % mod2;
        }
    }

    void init(string &s) {
        h[0] = {5389ULL, 5389ULL};
        for (size_t i = 0; i < s.size(); i++) {
            int code = s[i];
            h[i+1].first = (h[i].first * p + code) % mod;
            h[i+1].second = (h[i].second * p2 + code) % mod2;
        }
    }

    pair<uint64_t, uint64_t> get_hash(int i, int j) {
        pair<uint64_t, uint64_t> r;
        r.first = (h[j+1].first - (h[i].first * ppow[j-i+1]) % mod + mod) % mod;
        r.second = (h[j+1].second - (h[i].second * ppow2[j-i+1]) % mod2 + mod2) % mod2;
        return r;
    }
} h, h2;

int main() {
    string a, b;
    int n;

    getline(cin, a);
    getline(cin, b);
    cin >> n;

    int l = a.size();
    int k = b.size();

    h.init(a);
    h2.init(b);

    int lo = 0, hi = k, mid, ans = 0;

    while (lo <= hi) {
        mid = (lo + hi) / 2;

        int cnt = 0;
        for (int i = 0; i <= l-mid; i++) {
            if (h.get_hash(i, i+mid-1) == h2.get_hash(0, mid-1)) {
                cnt++;
            }
        }

        if (cnt >= n) {
            ans = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    if (ans == 0)
        cout << "IMPOSSIBLE\n";
    else
        cout << b.substr(0, ans) << "\n";
    return 0;
}

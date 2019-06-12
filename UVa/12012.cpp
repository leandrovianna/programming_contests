// Uva - Detection of Extraterrestrial - 12012
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

struct Hash {
    uint64_t h[N], ppow[N], p, mod;

    Hash() : p(33), mod(1000000007) {
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    string s;
    int ans[N];

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> s;
        int n = s.size();

        Hash h;
        h.init(s);

        for (int i = 0; i <= n; i++) {
            ans[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int m = j-i+1;
                for (int k = 1; k * k <= m; k++) {
                    if (m % k != 0) continue;

                    bool ok = true;
                    for (int p = i+k; p <= j; p += k) {
                        if (h.get_hash(p, p+k-1) != h.get_hash(p-k, p-1)) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        // s[i, j] is k-regular
                        ans[m/k] = max(ans[m/k], m);
                    }

                    if (m/k == k) continue;

                    ok = true;
                    int l = m / k;
                    for (int p = i+l; p <= j; p += l) {
                        if (h.get_hash(p, p+l-1) != h.get_hash(p-l, p-1)) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        // s[i, j] is m/k-regular
                        ans[k] = max(ans[k], m);
                    }
                }
            }
        }

        cout << "Case #" << ti << ":";
        for (int i = 1; i <= n; i++) {
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}

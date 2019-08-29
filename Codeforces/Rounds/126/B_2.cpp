// Codeforces - Password - 126B Div1
// solution using Hash
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
const uint64_t E = 33;
const uint64_t C = 5381ULL;
const uint64_t MOD = int(1e9) + 7;

struct Hash {
    vector<int> v;
    uint64_t h[N];
    uint64_t poww[N];

    Hash() {
        poww[0] = 1ULL;
        for (int i = 1; i < N; i++) {
            poww[i] = poww[i-1] * E;
            poww[i] %= MOD;
        }

        for (int i = 0; i < 26; i++) {
            v.push_back(i);
        }

        srand(time(nullptr));
        random_shuffle(v.begin(), v.end());
    }

    void init(string s) {
        int n = s.size();
        h[0] = C;
        for (int i = 0; i < n; i++) {
            h[i+1] = h[i] * E + v[s[i] - 'a'];
            h[i+1] %= MOD;
        }
    }

    uint64_t get_hash(int i, int j) {
        return ((h[j+1] - (h[i] * poww[j-i+1]) % MOD) + MOD) % MOD;
    }
};

Hash h1;

int main() {
    string s;

    cin >> s;

    int n = s.size();
    h1.init(s);

    string ans = "Just a legend";

    for (int l = n-1; l >= 1; l--) {
        if (h1.get_hash(0, l-1) == h1.get_hash(n - l, n - 1)) {
            uint64_t h = h1.get_hash(0, l-1);
            for (int i = 1; i < n - l; i++) {
                if (h1.get_hash(i, i + l - 1) == h) {
                    ans = s.substr(0, l);
                    l = 1; // break outer loop
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

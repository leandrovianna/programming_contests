// String Hash - Polynomial rolling hash
// Codeforces - Equivalent Strings - 559B
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
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

Hash h1, h2;
string s1, s2;

bool solve(int l, int r, int x, int y) {
    if (h1.get_hash(l, r) == h2.get_hash(x, y)) {
        return true;
    } else if ((r - l + 1) % 2 == 0) {
        int mid1 = (l + r) >> 1, mid2 = (x + y) >> 1;

        return (solve(l, mid1, x, mid2) && solve(mid1+1, r, mid2+1, y))
            || (solve(mid1+1, r, x, mid2) && solve(l, mid1, mid2+1, y));
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;
    
    h1.init(s1);
    h2.init(s2);

    if (solve(0, s1.size() - 1, 0, s2.size() - 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

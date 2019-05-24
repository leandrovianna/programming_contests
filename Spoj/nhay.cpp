// Spoj - A Needle in the Haystack - NHAY
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

Hash hp, h;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string pattern, text;

    while (cin >> n) {
        pattern = "";
        char ch;
        for (int i = 0; i < n; i++) {
            cin >> ch;
            pattern += ch;
        }
        cin.ignore();
        getline(cin, text);

        hp.init(pattern);
        h.init(text);

        int m = text.size();
        for (int i = 0; i < m - n + 1; i++) {
            if (hp.get_hash(0, n - 1) == h.get_hash(i, i + n - 1)) {
                cout << i << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}

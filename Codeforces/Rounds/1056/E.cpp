#include <bits/stdc++.h>
using namespace std;

const int N = 1001000;
const uint64_t E = 33;
const uint64_t C = 5381ULL;
const uint64_t MOD = int(1e9) + 7;

vector<int> v;
uint64_t h[N];
uint64_t poww[N];

void pre_hash(string s) {
    int n = s.size();
    poww[0] = 1ULL;
    for (int i = 1; i < N; i++) {
        poww[i] = poww[i-1]*E;
        poww[i] %= MOD;
    }
    for (int i = 0; i < 26; i++) {
        v.push_back(i);
    }
    srand(time(nullptr));
    random_shuffle(v.begin(), v.end());

    h[0] = C;
    for (int i = 0; i < n; i++) {
        h[i+1] = h[i] * E + v[s[i] - 'a'];
        h[i+1] %= MOD;
    }
}

uint64_t get_hash(int i, int j) {
    return ((h[j+1] - (h[i] * poww[j-i+1]) % MOD) + MOD) % MOD;
}

int main() {
    string s, t;
    
    cin >> s >> t;

    pre_hash(t);

    int zeros = count(s.begin(), s.end(), s[0]);
    int answer = 0;

    for (int i = 1, sz = t.size(); i < sz; i++) {
        bool not_init = false;
        uint64_t r0 = get_hash(0, i-1), r1 = 0;
        if (sz - zeros * i <= 0 || (sz - zeros * i) % (s.size() - zeros) != 0) {
            continue;
        }
        int k = (sz - zeros * i) / (s.size() - zeros);

        bool ok = true;

        int j = 0;
        for (const auto &ch : s) {
            if (ch == s[0]) {
                if (j+i > sz || get_hash(j, j+i-1) != r0) {
                    ok = false;
                    break;
                }
                j += i;
            } else {
                if (j+k > sz) {
                    ok = false;
                    break;
                }

                if (!not_init) {
                    not_init = true;
                    r1 = get_hash(j, j+k-1);
                }

                if (r1 != get_hash(j, j+k-1)) {
                    ok = false;
                    break;
                }

                j += k;
            }
        }

        if (ok && r1 != r0 && j == sz) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}

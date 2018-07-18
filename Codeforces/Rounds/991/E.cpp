// Codeforces - Bus Number - 991E Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 21;
int64_t fac[N];
void factorial(int n) {
    assert(n < N);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i-1] * i;
    }
}


// calculate number of distinct permutations
int64_t count(int cnt[]) {
    int n = 0;
    for (int d = 0; d < 10; d++) {
        n += cnt[d];
    }

    int64_t result = fac[n];

    for (int d = 0; d < 10; d++) {
        result /= fac[cnt[d]];
    }

    return result;
}

int main() {
    factorial(20);
    set<string> memo;

    const int M = 10;
    int cnt[M];
    bool mark[M];
    memset(cnt, 0, sizeof(cnt));
    memset(mark, 0, sizeof(mark));

    string num;
    cin >> num;

    for (const auto &c : num) {
        mark[c - '0'] = true;
    }

    int64_t ans = 0;

    for (int mask = 0; mask < (1 << num.size()); mask++) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < (int) num.size(); i++) {
            if (mask & (1 << i)) {
                cnt[num[i] - '0']++;
            }
        }

        bool valid = true;
        for (int d = 0; d < 10; d++) {
            if (mark[d] && cnt[d] == 0) {
                valid = false;
                break;
            }
        }

        string s = "";
        for (int d = 0; d < 10; d++) {
            s += string((char)('0' + d), cnt[d]);
        }

        if (valid && memo.count(s) == 0) {
            memo.insert(s);
            ans += count(cnt);

            // removing permutations with leading zero
            if (cnt[0] > 0) {
                cnt[0]--;
                ans -= count(cnt);
                cnt[0]++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

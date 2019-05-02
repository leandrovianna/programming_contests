// UVA - Mint - 10717
#include <bits/stdc++.h>
using namespace std;

int64_t lcm(int64_t a, int64_t b) {
    return a * (b / __gcd(a, b));
}

const int N = 50, INF = 1000 * 1000 * 1000;
int a[N];
int n, t;

void compute(vector<int> &len, int i,  int acc, int cnt) {
    if (cnt == 4) {
        len.push_back(acc);
    }

    if (i == n)
        return;

    compute(len, i+1, lcm(acc, a[i]), cnt+1);
    compute(len, i+1, acc, cnt);
}

int main() {
    while (cin >> n >> t, n || t) {
        vector<int> len;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<bool> v(n);
        fill(v.begin(), v.begin() + 4, true);
        do {
            int lcm_acc = 1;
            for (int i = 0; i < n; i++) {
                if (v[i]) {
                    lcm_acc = lcm(lcm_acc, a[i]);
                }
            }

            len.push_back(lcm_acc);

        } while (prev_permutation(v.begin(), v.end()));

        for (int i = 0, x; i < t; i++) {
            cin >> x;

            int lower = 0, upper = INF;

            for (const auto &l : len) {
                lower = max(lower, (x / l) * l);
                upper = min(upper, ((x+l-1) / l) * l);
            }

            cout << lower << " " << upper << "\n";
        }
    }

    return 0;
}

// Codeforces - Multi-Subject Competition - 1082C Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
multiset<int64_t, greater<>> in[N];
int64_t all_ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, si;
    int64_t ri;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> si >> ri;
        in[si].insert(ri);
    }

    int64_t acc;
    int maxj = 0;
    for (int i = 1; i <= m; i++) {
        acc = 0;
        int j = 0;
        for (const auto &x : in[i]) {
            acc += x;
            if (acc >= 0)
                all_ans[j] += acc;
            j++;
        }
        maxj = max(maxj, j);
    }

    int64_t ans = 0;

    for (int j = 0; j <= maxj; j++) {
        ans = max(ans, all_ans[j]);
    }

    cout << ans << "\n";

    return 0;
}

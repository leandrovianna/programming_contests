// AtCoder - Code Festival 2017 - D - Zabuton
#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int64_t dp[N];
pair<int64_t, int64_t> part[N];

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> part[i].first >> part[i].second;
        // h_i, p_i
    }
    
    dp[0] = 0;
    for (int used = 1; used <= n; used++) {
        dp[used] = LLONG_MAX;
    }

    sort(part, part+n, [](const auto &a, const auto &b) {
            return a.first + a.second < b.first + b.second;
        });

    for (int i = 0; i < n; i++) {
        for (int used = i+1; used >= 1; used--) {
            if (dp[used-1] != LLONG_MAX && part[i].first >= dp[used-1]) {
                dp[used] = min(dp[used], part[i].second + dp[used-1]);
            }
        }
    }

    for (int used = n; used >= 1; used--) {
        if (dp[used] != LLONG_MAX) {
            cout << used << endl;
            break;
        }
    }

    return 0;
}

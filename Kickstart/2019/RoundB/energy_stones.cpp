// Kickstart 2019 - Round B - Energy Stones
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int dp[N][N * N];

struct stone {
    int s, e, l;

    bool operator<(const stone &other) {
        return e - other.l > other.e - l;
        //return e + other.e - other.l * s > other.e + e - l * other.s;
    };
} stones[N];

int main() {
    int t, n;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> stones[i].s
                >> stones[i].e
                >> stones[i].l;
        }

        sort(stones, stones+n);

        for (int i = 0; i < N*N; i++) {
            dp[0][i] = 0;
        }

        for (int used = 1; used <= n; used++) {
            for (int i = 0; i < N*N; i++) {
                dp[used][i] = INT_MIN;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int used = i+1; used >= 1; used--) {
                for (int sec = stones[i].s; sec < N*N; sec++) {
                    if (dp[used-1][sec - stones[i].s] != INT_MIN) {
                        //cout << dp[used-1][sec - stones[i].s] << endl;
                        dp[used][sec] = max(dp[used][sec], dp[used-1][sec - stones[i].s] 
                                + max(0, stones[i].e - stones[i].l * (sec - stones[i].s)));
                    }
                }
            }
        }

        int answer = INT_MIN;
        for (int i = 0; i < N*N; i++) {
            answer = max(answer, dp[n][i]);
        }

        cout << "Case #" << ti << ": " << answer << "\n";
    }
    return 0;
}

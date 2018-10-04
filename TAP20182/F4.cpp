// TAP 2018/2 - Festival
#include <bits/stdc++.h>
using namespace std;

struct show {
    int i, f, o, p, idx;

    bool operator< (const show &other) {
        return i < other.i 
            || (i == other.i && idx < other.idx);
    }
};

const int N = 1010, V = 1 << 10;
show shows[N];
int prox[N];
int k = 0;

const int INF = 10000000;
int dp[N][V];
int n;

// dp recursiva
int solve(int i, int vis) {
    if (i >= k) {
        if (vis == (1 << n)-1) {
            return 0;
        } else {
            return -INF;
        }
    }

    if (dp[i][vis] != 0)
        return dp[i][vis];

    int &ans = dp[i][vis];

    ans = max(-INF, shows[i].o + solve(prox[i], vis | (1 << shows[i].p)));
    ans = max(ans, solve(i+1, vis));

    return ans;
}

int main() {
    scanf("%d", &n);

    for (int i = 0, m; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0, ini, fim, o; j < m; j++) {
            scanf("%d %d %d", &ini, &fim, &o);
            shows[k++] = {ini, fim, o, i, i * n + j};
        }
    }

    // pre processamento para descobrir proximo show apos ir ao show i
    sort(shows, shows+k);

    for (int i = 0; i < k; i++) {
        prox[i] = k;
        for (int j = i+1; j < k; j++) {
            if (shows[i].f <= shows[j].i) {
                prox[i] = j;
                break;
            }
        }
    }

    // dp interativa
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < k; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[i][mask] >= 0) {
                dp[i+1][mask] = max(dp[i+1][mask], dp[i][mask]);
                dp[prox[i]][mask | (1 << shows[i].p)] = max(dp[prox[i]][mask | (1 << shows[i].p)], 
                        dp[i][mask] + shows[i].o);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp[i][(1 << n)-1]);
    }
    printf("%d\n", (ans <= 0 ? -1 : ans));

    return 0;
}

//UVa - Making Change - UVA 166
#include <bits/stdc++.h>
using namespace std;

const int COINS[] = {5, 10, 20, 50, 100, 200};
const int V = 10010;
const int MAX = 10000;
int dp[V], skdp[V];
const int N = 110;
const int inf = 0x3F3F3F3F;
int coins[N];
int qtcoins[10];
int n;

int main() {
    ios::sync_with_stdio(false);

    memset(skdp, inf, sizeof(skdp));
    skdp[0] = 0;
    for (int j = 0; j < 6; j++) {
        for (int i = MAX; i >= 0; i--) {
            if (i - COINS[j] >= 0 && skdp[i-COINS[j]] != inf) {
                skdp[i] = min(skdp[i], skdp[i-COINS[j]] + 1);
            }
        }
    }

    while (true) {
        bool fim = true;
        for (int i = 0; i < 6; i++) {
            scanf("%d", &qtcoins[i]);
            if (qtcoins[i] != 0)
                fim = false;
        }

        if (fim)
            break;

        int x, y;
        scanf("%d.%d", &x, &y);
        x = x * 100 + y;

        n = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < qtcoins[i]; j++)
                coins[n++] = COINS[i];
        }

        memset(dp, inf, sizeof(dp));
        dp[0] = 0;
        for (int j = 0; j < n; j++) {
            for (int i = MAX; i >= 1; i--) {
                if (i - coins[j] >= 0 && dp[i-coins[j]] != inf) {
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }


        int answer = inf;
        for (int k = 0; x + k <= MAX; k++) {
            answer = min(dp[x + k] + skdp[k], answer);
        }

        cout << setw(3) << answer << endl;
    }
    return 0;
}

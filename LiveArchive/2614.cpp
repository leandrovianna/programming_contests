// Live Archive - 2614 - Duty Free Shop - ICPC South America 2002
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int box[N], tot[N];
bool dp[N];
int used[N], vis = 1;

int main() {
    int m, l, n;

    while (cin >> m >> l, m || l) {
        cin >> n;
        tot[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> box[i];
            tot[i+1] = box[i] + (i > 0 ? tot[i-1] : 0);
        }

        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int a = m; a >= 0; a--) {
                int b = abs(tot[i] - a);
                if (b <= l && a - box[i] >= 0) {
                    dp[a] |= dp[a - box[i]];
                }
            }
        }
    }

    return 0;
}

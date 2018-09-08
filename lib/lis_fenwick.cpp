// LIS using Fenwick Tree
#include <bits/stdc++.h>
using namespace std;

const int M = 310;
int ft[M];

void update(int x, int v) {
    while (x < M) {
        ft[x] = max(ft[x], v);
        x += (x & -x);
    }
}

int query(int x) {
    int ans = 0;
    while (x > 0) {
        ans = max(ans, ft[x]);
        x -= (x & -x);
    }
    return ans;
}

int dp[1000100];

int main() {
    const int N = 110, V = 310;
    int n, t;
    int a[N], cnt[V], qt = 0;

    memset(cnt, 0, sizeof(cnt));
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        qt = max(qt, cnt[a[i]]);
    }

    int lis = 1, x = min(1000,t);

    for (int i = 0; i < x*n; i++) {
        dp[i] = query(a[i%n]) + 1;
        update(a[i%n], dp[i]);
        lis = max(lis, dp[i]);
    }

    if (t == 1) {
        cout << *max_element(dp, dp+n) << endl;
    } else {
        cout << lis + (t - x) * qt << endl;
    }

    return 0;
}

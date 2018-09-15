// LIS using Fenwick Tree
#include <bits/stdc++.h>
using namespace std;

const int M = 310;
int ft[M];

void update(int x, int v) {
    x += 3;
    while (x < M) {
        ft[x] = max(ft[x], v);
        x += (x & -x);
    }
}

int query(int x) {
    x += 3;
    int ans = 0;
    while (x > 0) {
        ans = max(ans, ft[x]);
        x -= (x & -x);
    }
    return ans;
}

int dp[1000100];

int main() {
    const int N = 110;
    int n;
    int64_t a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lis = 1;

    for (int i = 0; i < n; i++) {
        dp[i] = query(a[i%n]-1) + 1;
        update(a[i%n], dp[i]);
        lis = max(lis, dp[i]);
    }

    cout << lis << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int cnt[N+10];

int main() {
    int n, k;

    cin >> n >> k;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    int e = 0;
    for (int i = 1; i <= N; i++) {
        e = max(e, cnt[i]);
    }

    if (e % k != 0) {
        e += k - (e % k);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] > 0)
            ans += e - cnt[i];
    }

    cout << ans << endl;
    return 0;
}

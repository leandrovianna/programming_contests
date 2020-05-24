// Codeforces - Multiset - 1354D
#include <bits/stdc++.h>
using namespace std;

const int N = 1000010; // 10^6

int ft[N];

void update(int x, int v) {
    while (x < N) {
        ft[x] += v;
        x += (x & -x);
    }
}

int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += ft[x];
        x -= (x & -x);
    }

    return sum;
}

void multiset_add(int x) {
    update(x, 1);
}

int multiset_remove_order(int ord) {
    int mid, lo = 1, hi = N-1, ans = 0;

    while (lo <= hi) {
        mid = (lo + hi) >> 1;

        if (ord <= query(mid)) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    if (ans > 0)
        update(ans, -1);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        multiset_add(x);
    }

    for (int i = 0, x; i < q; i++) {
        cin >> x;
        if (x > 0) {
            multiset_add(x);
        } else {
            multiset_remove_order(-x);
        }
    }

    cout << multiset_remove_order(1) << "\n";

    return 0;
}

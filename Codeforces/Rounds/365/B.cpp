#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100 * 1000 + 10;
    int n;
    int64_t a[N];
    bool mark[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mark[i] = false;
    }

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    for (int i = 2; i < n; i++) {
        if (a[i] == a[i-1] + a[i-2]) {
            mark[i] = true;
        }
    }

    int ans = 2;
    int local_ans = 2;
    for (int i = 2; i < n; i++) {
        if (mark[i]) {
            local_ans++;
        } else {
            ans = max(ans, local_ans);
            local_ans = 2;
        }
    }

    ans = max(ans, local_ans);

    cout << ans << endl;
    return 0;
}

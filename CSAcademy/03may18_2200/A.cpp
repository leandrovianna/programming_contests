#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int cnt[N];

int main() {
    int n, k, distinct, ans;
    string s;

    cin >> n >> k;
    ans = -1;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (const auto &c : s) {
            cnt[c-'a'] = 1;
        }

        distinct = 0;
        for (int j = 0; j < N; j++) {
            if (cnt[j] != 0)
                distinct++;
        }

        if (distinct <= k) {
            ans = max(ans, (int)s.size());
        }

        memset(cnt, 0, sizeof(cnt));
    }

    cout << ans << endl;
    return 0;
}

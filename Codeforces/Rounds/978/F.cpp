// Codeforces - Mentors - 978E Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 * 2 + 10;
int r[N], a[N];
int vis[N], curr_vis = 1;
vector<int> quarrel[N];

int howmuch(int v, const int n) {
    auto it = lower_bound(a, a+n, r[v]);
    return it - a;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;

    cin >> n >> k;

    for (int v = 1; v <= n; v++) {
        cin >> r[v];
        a[v-1] = r[v];
    }

    sort(a, a+n);

    for (int i = 0, x, y; i < k; i++) {
        cin >> x >> y;
        quarrel[x].push_back(y);
        quarrel[y].push_back(x);
    }

    for (int v = 1; v <= n; v++) {
        int ans = howmuch(v, n);
        for (const auto &u : quarrel[v]) {
            if (r[u] < r[v]) {
                ans--;
            }
        }
        cout << ans << " ";
        curr_vis++;
    }
    cout << endl;

    return 0;
}

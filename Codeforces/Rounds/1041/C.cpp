// Codeforces - Coffee Break - 1041C Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int64_t a[N], ans[N];
map<int64_t, int> id;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int64_t m, d;

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }

    sort(a, a+n);
    int64_t days = 1;
    set<int64_t> lasts;
    lasts.insert(a[0]);
    ans[id[a[0]]] = days;

    for (int i = 1; i < n; i++) {
        auto it = lasts.begin();

        if (a[i] - *it > d) {
            ans[id[a[i]]] = ans[id[*it]];
            lasts.erase(it);
        } else {
            days++;
            ans[id[a[i]]] = days;
        }

        lasts.insert(a[i]);
    }

    cout << days << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}

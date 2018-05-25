// Codeforces - Burglar and Matches - 16B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    const int N = 20;
    pair<int, int> container[N];
    int64_t a, b;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        container[i] = {a, b};
    }

    sort(container, container+m, [](auto x, auto y) {
                return x.second > y.second;
            });

    int ans = 0, bag = 0;
    for (int i = 0; i < m; i++) {
        if (bag + container[i].first <= n) {
            bag += container[i].first;
            ans += container[i].second * container[i].first;
        } else {
            ans += (n - bag) * container[i].second;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}

// Codeforces - Watchmen - 651C - Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    map<int, int64_t> cntx, cnty;
    map<pair<int, int>, int64_t> qtd;

    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        cntx[x]++;
        cnty[y]++;
        qtd[{x, y}]++;
    }

    int64_t ans = 0;
    for (const auto &line : cntx) {
        ans += line.second * (line.second - 1) / 2;
    }

    for (const auto &line : cnty) {
        ans += line.second * (line.second - 1) / 2;
    }

    for (const auto &p : qtd) {
        ans -= p.second * (p.second - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}

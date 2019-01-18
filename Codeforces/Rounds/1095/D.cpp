// Codeforces - Circular Dance - 1095D Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int g[N][2], n;
vector<int> ans;
set<int> vis;

bool solve(int v, int w) {
    if ((int) vis.size() == n)
        return true;

    if (vis.count(v))
        return false;
    vis.insert(v);

    if (w == g[v][0] && solve(g[v][0], g[v][1])) {
        ans.push_back(w);
        return true;
    } else if (w == g[v][1] && solve(w, g[v][0])) {
        ans.push_back(w);
        return true;
    } else {
        vis.erase(v);
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1, x1, x2; i <= n; i++) {
        cin >> x1 >> x2;
        g[i][0] = x1;
        g[i][1] = x2;
    }

    if (!solve(1, g[1][0]))
        solve(1, g[1][1]);

    reverse(ans.begin(), ans.end());
    for (const auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

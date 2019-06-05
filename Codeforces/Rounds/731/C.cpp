// Codeforces - Socks - 731C
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int color[N];

struct UnionFind {
    int p[N], s[N];
    void init(int n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
            s[i] = 1;
        }
    }

    int find(int x) {
        if (p[x] == x) return x;
        else return p[x] = find(p[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        if (s[x] > s[y]) {
            p[y] = x;
            s[x] += s[y];
        } else {
            p[x] = y;
            s[y] += s[x];
        }
    }
} uf;

map<int, int> cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    uf.init(n);

    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        uf.join(l-1, r-1);
    }

    set<int> comps;
    for (int i = 0, c; i < n; i++) {
        c = uf.find(i);
        comps.insert(c);
        cnt[c][color[i]]++;
    }

    int ans = 0;
    for (const auto &c : comps) {
        int maxqtd = 0;
        for (const auto &p : cnt[c]) {
            maxqtd = max(p.second, maxqtd);
        }
        ans += uf.s[c] - maxqtd;
    }

    cout << ans << "\n";

    return 0;
}

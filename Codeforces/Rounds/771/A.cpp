// Codeforces - Bear and Friendship Condition - 771A
#include <bits/stdc++.h>
using namespace std;

const int N = 150100;
struct UnionFind {
    int parent[N], size[N];

    void init(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        } else {
            return find(parent[x]);
        }
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
    }
} uf;

int64_t cnt_edges[N];
int64_t cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    uf.init(n);

    vector<pair<int, int>> edges;

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        edges.push_back({a, b});
        uf.join(a, b);
    }

    for (const auto &e : edges) {
        cnt_edges[uf.find(e.first)]++;
    }

    for (int i = 0; i < n; i++) {
        cnt[uf.find(i)]++;
    }

    for (int i = 0; i < n; i++) {
        int leader = uf.find(i);
        if (cnt_edges[leader] != (cnt[leader] * (cnt[leader] - 1)) / 2) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}

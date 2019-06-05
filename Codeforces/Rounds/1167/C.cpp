// Codeforces - News Distribution - 1167C
#include <bits/stdc++.h>
using namespace std;


const int N = 500100;

struct UnionFind {
    int parent[N], size[N];

    void init(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(parent[x]);
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

int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    uf.init(n+1);

    for (int i = 0, k; i < m; i++) {
        cin >> k;
        for (int j = 0, x, y = -1; j < k; j++) {
            cin >> x;
            if (y != -1) {
                uf.join(x, y);
            }
            y = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        cnt[uf.find(i)]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt[uf.find(i)] << " ";
    }
    cout << "\n";
    return 0;
}

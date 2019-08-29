// Codeforces - Ice Skating - 217A
#include <bits/stdc++.h>
using namespace std;

const int N = 110;

struct SnowDrift {
    int x, y;
} p[N];

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
            return find(parent[x]);
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

int main() {
    int n;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    uf.init(n);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].x == p[j].x || p[i].y == p[j].y) {
                uf.join(i, j);
            }
        }
    }

    set<int> comps;
    for (int i = 0; i < n; i++) {
        comps.insert(uf.find(i));
    }

    cout << comps.size() - 1 << "\n";
    return 0;
}

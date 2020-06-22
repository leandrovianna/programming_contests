#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int M = N*N;
pair<int, int> p[N];

struct Edge {
    int x, y;
    double w;
} edges[M];

bool operator<(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

namespace UF {
    int parent[N];
    int size[N];

    void init(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    int edges_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            edges[edges_size++] = {i, j, hypot(p[i].first - p[j].first,
                    p[i].second - p[j].second)};
        }
    }

    sort(edges, edges+edges_size);

    double ans = 0;

    UF::init(n);

    for (int i = 0; i < edges_size; i++) {
        int x = edges[i].x;
        int y = edges[i].y;
        double w = edges[i].w;

        if (UF::find(x) != UF::find(y)) {
            UF::join(x, y);
            ans += w;
        }
    }

    cout << fixed << setprecision(10);
    cout << ans << "\n";

    return 0;
}


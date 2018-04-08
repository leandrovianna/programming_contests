//Codeforces - Forming Teams - 216B
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int parent[N], sz[N];

void init(const int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        parent[y] = x;
        sz[x] += sz[y];
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;

    init(n+1);
    int ans = 0;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (find(x) == find(y) && sz[find(x)] & 1) {
            ans++;
        }
        join(x, y);
    }

    if ((n - ans) & 1) {
        ans++;
    }
    
    cout << ans << endl;

    return 0;
}

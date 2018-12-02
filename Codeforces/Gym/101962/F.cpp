#include <bits/stdc++.h>
using namespace std;

namespace UF {
	const int N = 100 * 1000 + 10;
	int parent[N];
	int sz[N];
	int a[N];
	void init(int size) {
	    assert(size < N);
		for (int i = 0; i < size; i++) {
			parent[i] = i;
			sz[i] = 1;
        }
	}
	int value(int x) {
		if (parent[x] == x) return a[x];
		else return value(parent[x]);
	}
	int find(int x) {
		if (parent[x] == x) return x;
		else return parent[x] = find(parent[x]);
	}
	void join(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return;

        if (sz[x] < sz[y]) {
            parent[x] = y;
            sz[y] += sz[x];
            a[y] = max(a[x], a[y]);
        } else {
            parent[y] = x;
            sz[x] += sz[y];
            a[x] = max(a[x], a[y]);
        }
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r;

    cin >> n >> l >> r;

    set<pair<int, int>> ss;

    for (int i = 0; i < n; i++) {
        cin >> UF::a[i];
        ss.insert({UF::a[i], i});
    }

    UF::init(n+1);

    for (const auto &p : ss) {
        int j = p.second;
        int v1 = (j > 0 ? UF::value(j-1) : 0);
        int v2 = (j < n-1 ? UF::value(j+1) : 0);
        
        if (v1 > v2 && UF::sz[UF::find(j-1)] + UF::sz[UF::find(j)] <= r) {
            UF::join(j, j-1);
        } else if (j < n-1 && UF::value(j+1) >= UF::value(j) && UF::sz[UF::find(j+1)] + UF::sz[UF::find(j)] <= r) {
            UF::join(j, j+1);
        }
    }

    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        ans = min(ans, UF::value(i));
    }

    cout << ans << "\n";
    return 0;
}

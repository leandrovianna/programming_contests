#include <bits/stdc++.h>
using namespace std;

const int N = 1000 * 1000 * 1000 + 20;
map<int, int> bit;

// execute the query [1, x]
int query(int x) {
    x += 3;
	int s = 0;
	
	while (x) {
		s += bit[x];
		x -= (x & -x);
	}

	return s;
}

// execute the update [1,x]
void update(int x, int v) {
    x += 3;
	while (x < N) {
		bit[x] += v;
		x += (x & -x);
	}
}

const int M = 100 * 1000 + 10;
int64_t v[M];
pair<int64_t, int64_t> x[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    v[n] = 1e9;

    for (int i = 0, y; i < m; i++) {
        cin >> x[i].first >> x[i].second >> y;
    }

    sort(v, v+n);
    sort(x, x+m);

    for (int j = 0; j < m; j++) {
        if (x[j].first == 1)
            update(x[j].second, 1);
    }

    int ans = n+m+10, lans;
    for (int i = 0; i <= n; i++) {
        lans = i + query(N-5) - query(v[i]-1);
        ans = min(ans, lans);
    }

    cout << ans << "\n";
    return 0;
}

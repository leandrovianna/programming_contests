//CodePit - Non-boring sequences - A
//LiveArchive - '' - 6258
#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int pv[N], nx[N], v[N];
map<int, int> p;

bool is_unique(int i, int l, int r) {
	return pv[i] < l && nx[i] > r;
}

bool solve(int l, int r) {
	if (l >= r) {
		return true;
	}

	int d;
	for (d = 0; l+d < r-d; d++) {
		if (is_unique(l+d, l, r))
			return solve(l, l+d-1) && solve(l+d+1, r);
		if (is_unique(r-d, l, r))
			return solve(l, r-d-1) && solve(r-d+1, r);
	}

	if (l+d == r-d && is_unique(l+d, l, r))
		return solve(l, l+d-1) && solve(l+d+1, r);

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		p.clear();
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (p.count(v[i]))
				pv[i] = p[v[i]];
			else
				pv[i] = -1;

			p[v[i]] = i;
		}
		p.clear();
		for (int i = n-1; i >= 0; i--) {
			if (p.count(v[i]))
				nx[i] = p[v[i]];
			else
				nx[i] = n;
			p[v[i]] = i;
		}

		cout << (solve(0, n-1) ? "non-boring" : "boring") << "\n";
	}

	return 0;
}

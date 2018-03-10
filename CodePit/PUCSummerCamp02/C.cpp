//CodePit - Valera and Elections - C
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int n;
vector<pair<int, bool> > g[N];
vector<int> ans;

bool dfs(int v, int p, bool need) {
	bool r = false;
	for (const auto &e : g[v]) {
		int u = e.first;
		if (u == p) continue;
		r |= dfs(u, v, e.second);
	}

	if (r) need = false;

	if (need) {
		ans.push_back(v);
		r = true;
	}

	return r;
}

int main() {
	ios::sync_with_stdio(false);
	int a, b, w;

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> w;
		g[a].push_back({b, w == 2});
		g[b].push_back({a, w == 2});
	}

	dfs(1, 0, false);

	cout << ans.size() << endl;
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it;
		if (it != prev(ans.end()))
			cout << " ";
		else
			cout << endl;
	}

	return 0;
}

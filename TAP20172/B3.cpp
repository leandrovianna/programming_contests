#include <bits/stdc++.h>
using namespace std;

set<int> ans;

void solve(vector<int> &b, vector<int> &p, int i, int left, int right) {
	if (p.size() == i) {
		if (left == right)
			for (auto &x : b) ans.insert(x + left + right);
		else return;
	}
	else {
		solve(b, p, i+1, left, right);
		solve(b, p, i+1, left+p[i], right);
		solve(b, p, i+1, left, right+p[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	const int N = 15;
	int n, m, x;
	vector<int> b, p;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> x, b.push_back(x);
	for (int i = 0; i < m; i++)
		cin >> x, p.push_back(x);

	solve(b, p, 0, 0, 0);

	for (auto &x : ans) {
		cout << x << endl;
	}
	return 0;
}

//CodeChef - Chef And Easy Xor Queries - DEC17 CHEFXQ
#include <bits/stdc++.h>
using namespace std;

const int N = 100'010;
const int M = 10'000;

// a multiset<int> for each magical subarray possible
// with M-th update
// pre[i][j] -- all xor values for subarray 1...i at j-th update
vector<multiset<int> > pre[M];
vector<tuple<int, int, int> > queries;
vector<pair<int, int> > updates;

int main() {
	ios::sync_with_stdio(false);
	int n, q, x, op, j, arr[N];

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int nUpdates = 0;
	for (int i = 0; i < q; i++) {
		cin >> op >> j >> x;

		if (op == 1) {
			updates.push_back(make_pair(j, x));
			nUpdates++;
		} else {
			queries.push_back(make_tuple(nUpdates, j, x));
		}
	}

	int acc[N], gen = 0;
	multiset<int> ss;
	for (int i = 0; i < n; i++) {
		if (i > 0)
			acc[i] = acc[i-1] ^ arr[i];
		else
			acc[i] = arr[i];

		ss.insert(acc[i]);
		// pre[gen][i] = ss;
		pre[gen].push_back(ss);
	}

	for (const auto &p : updates) {
		gen++;
		j = p.first;
		x = p.second;

		pre[gen] = pre[gen-1];

		for (int i = j; i < n; i++) {
			transform(pre[gen][i].begin(), pre[gen][i].end(),
					pre[gen][i].begin(),
					[&](auto elem) {
						return elem;
					});
		}
	}

	for (const auto &tup : queries) {
		gen = get<0>(tup);
		j = get<1>(tup) - 1;
		x = get<2>(tup);

		cout << pre[gen][j].count(x) << '\n';
	}

	return 0;
}

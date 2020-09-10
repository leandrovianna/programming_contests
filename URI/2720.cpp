//URI - Presentes Grandes - 2720
#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> a, const pair<int, int> b) {
	return a.first > b.first
		|| (a.first == b.first && a.second < b.second);
}

int main() {
	ios::sync_with_stdio(false);
	int t, n, k;
	int id, h, w, l;
	vector<pair<int, int> > ss;

	cin >> t;
	while (t--) {
		ss.clear();

		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> id >> h >> w >> l;
			ss.push_back({h * w * l, id});
		}

		sort(ss.begin(), ss.end(), comp);

		set<int> ids;
		for (int i = 0; i < k; i++) {
			ids.insert(ss[i].second);
		}

		for (auto it = ids.begin(); it != ids.end(); it++) {
			cout << *it;

			if (it != prev(ids.end()))
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}

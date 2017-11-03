//HackerRank - Mutual Indivisibility
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t, a, b;
	size_t x;

	cin >> t;
	while (t--) {
		cin >> a >> b >> x;
		vector<int> v;
		for (int i = b; i >= a; i--) {
			bool fl = true;
			for (auto &j : v) {
				if (j % i == 0) {
					fl = false;
					break;
				}
			}
			if (fl) v.push_back(i);
		}

		if (v.size() >= x) {
			for (auto it = v.begin(); it != v.begin()+x; it++) {
				cout << *it << " \n"[next(it) == v.begin()+x];	
			}
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}

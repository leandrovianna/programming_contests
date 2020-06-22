#include <bits/stdc++.h>
using namespace std;

typedef int int_type;
typedef pair<int_type, int_type> ii;

int64_t deliver(vector<ii> hn, int k) {
	if (hn.size() == 0) return 0;

	int64_t p = k, dist = 0;

	dist += abs(hn.front().first);

	for (size_t i = 0; i < hn.size(); i++) {
		if (i > 0) {
			dist += abs((int64_t)hn[i].first - hn[i-1].first);
		} 

		if (p >= hn[i].second) {
			p -= hn[i].second;
		} else {
			hn[i].second -= p;
			dist += ((int64_t)hn[i].second / k) * (abs(hn[i].first) * 2LL);

			if (hn[i].second % k) {
				dist += (abs(hn[i].first) * 2LL);
				p = k - (hn[i].second % k);
			} else p = 0;
		}
	}

	dist += abs(hn.back().first);

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	int n, k, x, m;
	vector<ii> hn, hp;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x >> m;
		if (x < 0) hn.push_back(ii(x, m));
		else hp.push_back(ii(x, m));
	}

	sort(hn.begin(), hn.end());
	sort(hp.begin(), hp.end(), greater<ii>());

	int64_t dist = 0;

	dist += deliver(hn, k);
	dist += deliver(hp, k);

	cout << dist << endl;
	return 0;
}

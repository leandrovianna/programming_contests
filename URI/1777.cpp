#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, c, e, qtd, p, x, y;

	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		vector<pair<int, int> > ranges;
		map<int, int> cams;

		cin >> n >> c;
		for (int i = 0; i < c; i++) {
			scanf("%d %d", &x, &y);
			ranges.push_back({x, y});
		}

		cin >> e;
		for (int i = 0; i < e; i++) {
			scanf("%d", &p);
			cams[p]++;
		}

		qtd = 0;
		for (int i = 0; i < c; i++) {
			auto it = cams.lower_bound(ranges[i].first);

			while (it != cams.end() && it->first <= ranges[i].second) {
				qtd++;
				auto at = next(it);
				cams[it->first]--;

				if (cams[it->first] == 0) {
					cams.erase(it->first);
					it = at;
				}
			}
		}

		printf("Caso #%d: %d\n", ti+1, qtd);
		ranges.clear();
		cams.clear();
	}
	return 0;
}

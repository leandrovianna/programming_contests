#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

typedef pair<int,int> ii;

int main() {
	ios::sync_with_stdio(false);
	int n, k, s, e;

	vector<ii> intervals;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		intervals.push_back(make_pair(e, s));
	}

	sort(intervals.begin(), intervals.end());

	multiset<int, greater<int>> tracks;
	for (int i = 0; i < k; i++)
		tracks.insert(0);

	int ans = 0;
	for (auto &p : intervals) {
		auto it = tracks.lower_bound(p.second);

		if (it != tracks.end()) {
			tracks.erase(it);
			tracks.insert(p.first);
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}

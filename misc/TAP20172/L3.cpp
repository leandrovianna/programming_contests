#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

bool test1(int a1, int a2, int b1, int b2, int c1, int c2) {
	return (a1 == b2 + c2) && (b1 == c1) && (a2 + b1 == a1);
}

bool test2(int a1, int a2, int b1, int b2, int c1, int c2) {
	return (a1 == b1) && (b1 == c1) && (a2 + b2 + c2 == a1);
}

bool test(vector<ii> v) {
	return test1(v[0].first, v[0].second,
				v[1].first, v[1].second,
				v[2].first, v[2].second)
		|| test2(v[0].first, v[0].second,
				v[1].first, v[1].second,
				v[2].first, v[2].second);
}


int main() {
	ios::sync_with_stdio(false);
	vector<ii> v;
	int x, y;

	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		v.push_back(ii(x,y));
	}

	sort(v.begin(), v.end());

	bool succ = false;

	do {
		for (int mask = 0; mask < (1 << v.size()); mask++) {
			for (size_t i = 0; i < v.size(); i++) {
				if (mask & (1 << i))
					swap(v[i].first, v[i].second);
			}

			succ |= test(v);

			for (size_t i = 0; i < v.size(); i++) {
				if (mask & (1 << i))
					swap(v[i].first, v[i].second);
			}
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << (succ ? "YES" : "NO") << endl;
	return 0;
}

//Codeforces - Divisibility of Differences - 876B
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, k, m, x;
	const int N = 1e5+10;
	multiset<int> cm[N];
	cin >> n >> k >> m;	

	for (int i = 0; i < n; i++) {
		cin >> x;
		cm[x%m].insert(x);
	}

	for (int i = 0; i < m; i++) {
		if (cm[i].size() >= (size_t)k) {
			cout << "Yes\n";
			int c = 0;
			for (auto it = cm[i].begin(); c < k && it != cm[i].end(); 
					c++, it++)
				cout << *it << " \n"[c == k-1];
			return 0;
		}
	}

	cout << "No\n";
	return 0;
}

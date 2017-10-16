//Codeforces - Search for Pretty Integers - 872A
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m, x;
	vector<int> l1, l2;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		l1.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		l2.push_back(x);
	}

	int ans = 10;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (l1[i] == l2[j])
				ans = min(ans, l1[i]);

	if (ans != 10)
		cout << ans << endl;
	else {
		int d1 = *min_element(l1.begin(), l1.end());
		int d2 = *min_element(l2.begin(), l2.end());
		cout << min(d1,d2) << max(d1,d2) << endl;
	}
	return 0;
}

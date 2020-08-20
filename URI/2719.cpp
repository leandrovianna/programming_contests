//URI - Quantas Viagens Fará o Noel - 2719
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m, p, t;

	cin >> t;

	while (t--) {
		cin >> n >> m;

		int viagens = 1;
		int x = m;
		for (int i = 0; i < n; i++) {
			cin >> p;
			x -= p;
			if (x < 0) {
				viagens++;
				x = m - p;
			}
		}
		cout << viagens << endl;
	}
	return 0;
}

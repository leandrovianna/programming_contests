//CodePit - Pasti Pas - F
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> s;

		int l = 0, r = s.size()-1;
		int ans = 0;
		uint64_t base = 33ULL;
		uint64_t hl = 0, hr = 0;
		uint64_t d = 1;
		while (l < r) {
			hl = hl * base + (1 + s[l] - 'A');
			hr = hr + d * (1 + s[r] - 'A');
			d *= base;

			if (hl == hr) {
				ans += 2;
				hl = hr = 0;
				d = 1;
			}

			l++;
			r--;
		}

		// segmentos diferentes com letra do meio
		// segmentos iguais (ja computados) e letra do meio
		if (hl != 0 || l == r) {
			ans++;
		}

		cout << "Case #" << ti << ": " << ans << endl;
	}

	return 0;
}

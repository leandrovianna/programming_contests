#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, k, resto, x, pa;
	const int N = 1010;
	pair<int, int> p[N];

	cin >>  n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p+n);

	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].first < 0 && p[i].second > 0) {
			//dist deixando todas as cartas em i
			ans += 2LL * abs((p[i].second / k) * p[i].first);
			resto = p[i].second % k;
			if (resto > 0) {
				// aumentando dist percorrida
				ans += 2LL * abs(p[i].first);
				pa = k - resto;

				// atualizar valores de cartas
				for (int j = i+1; j < n && p[j].first < 0; j++) {
					if (pa >= p[j].second) {
						pa -= p[j].second;
						p[j].second = 0;
					} else {
						p[j].second -= pa;
						pa = 0;
					}

					if (pa == 0) {
						break;
					}
				}
			}
		}
	}

	for (int i = n-1; i >= 0; i--) {
		if (p[i].first > 0 && p[i].second > 0) {
			//dist deixando todas as cartas em i
			ans += 2LL * abs((p[i].second / k) * p[i].first);
			resto = p[i].second % k;
			if (resto > 0) {
				// aumentando dist percorrida
				ans += 2LL * abs(p[i].first);
				pa = k - resto;

				// atualizar valores de cartas
				for (int j = i-1; j >= 0 && p[j].first > 0; j--) {
					if (pa >= p[j].second) {
						pa -= p[j].second;
						p[j].second = 0;
					} else {
						p[j].second -= pa;
						pa = 0;
					}

					if (pa == 0) {
						break;
					}
				}
			}
		}
	}

	cout << ans << '\n';
}

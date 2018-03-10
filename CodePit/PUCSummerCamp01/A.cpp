//Puc Summer Camp 2018
//URI - Transporte de Paineis Solares - 1579
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int c, f;
int p[N];

int solve(int peso_max) {
	int i = 0, j = 0;
	int64_t peso = 0;

	while (j < c) {
		while (i < n && peso + p[i] <= peso_max) {
			peso += p[i];
			i++;
		}

		peso = 0;
		j++;
	}

	if (i < n) {
		return 0;
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	const int M = 100 * 1000 + 10;

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> c >> f;
		for (int i = 0; i < n; i++)
			cin >> p[i];

		int low = 0, high = M, peso_max;

		int ans = 0;
		while (low <= high) {
			peso_max = (low + high) >> 1;

			if (solve(peso_max)) {
				ans = peso_max;
				high = peso_max-1;
			} else {
				low = peso_max+1;
			}
		}

		cout << ans << " $" << ans * f * c << endl;
	}
	return 0;
}

//URI - Treno Lotado - 2726
#include <bits/stdc++.h>
using namespace std;

const int CC = 60;
uint64_t comb[CC][CC];
uint64_t combination(int n, int k) {
	if (n < CC && k < CC)
		return comb[n][k];
	else
		return 0;
}

uint64_t toBinary(vector<uint64_t> pesos, uint64_t num) {
	uint64_t x = 0;
	uint64_t bit = 1ULL << (pesos.size()-1);

	for (const auto& p : pesos) {
		if (num >= p) {
			num -= p;
			x |= bit;
		}

		bit >>= 1ULL;
	}

	return x;
}

uint64_t countWays(uint64_t num, uint64_t qtd, uint64_t n) {
	uint64_t ways = 0;
	uint64_t bit = 1ULL << (n-1);

	for (int i = n-1; i >= 0; i--) {
		if (num & bit) {
			if ((uint64_t) i >= qtd) {
				ways += combination(i, qtd);
			}

			qtd--;
			if (qtd == 0) {
				ways++;
				break;
			}
		}

		bit >>= 1ULL;
	}

	return ways;
}

int main() {
	ios::sync_with_stdio(false);

	comb[0][0] = 1ULL;
	for (int i = 0; i < CC; i++) {
		comb[i][0] = 1ULL;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
		}
	}

	int t, n, k;
	uint64_t a, b;

	cin >> t;

	while (t--) {
		cin >> n >> k;

		vector<uint64_t> pesos(n);

		for (int i = 0; i < n; i++)
			cin >> pesos[i];

		cin >> a >> b;

		sort(pesos.begin(), pesos.end(), greater<uint64_t>());

		uint64_t ways = countWays(toBinary(pesos, b), k, n);

		if (a != 0) {
			ways -= countWays(toBinary(pesos, a) - 1ULL, k, n);
		}

		cout << ways << endl;
	}

	return 0;
}

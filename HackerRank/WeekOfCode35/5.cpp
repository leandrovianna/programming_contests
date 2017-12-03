//HackerRank - Highway Construction - WoC35
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'009; //10**9+9
const int K = 1010;

int64_t f[K];
int64_t comb[K][K];

int64_t mod(int64_t a) {
	return (a + MOD) % MOD;
}

//retorna um pair<int64_t, int64_t>, o primeiro 
//eh o coeficiente x e o segundo eh o y
pair<int64_t,int64_t> extendedEuclid(int64_t a, int64_t m) {
	if (m == 0) {
		return {1,0};
	} else {
		auto tmp = extendedEuclid(m, a%m);
		auto ans = pair<int64_t,int64_t>{0,0};
		ans.first = tmp.second;
		ans.second = tmp.first - (a/m) * tmp.second;
		return ans;
	}
}

int64_t invMod(int64_t a) {
	auto x = extendedEuclid(a, MOD);
	return (x.first + MOD) % MOD;
}

int64_t mypow(int64_t base, int64_t exp) {
	int64_t ans = 1;
	int64_t x = base;

	while (exp > 0) {
		if (exp & 1) {
			ans = (ans * x) % MOD;
			exp--;
		} else {
			x = (x * x) % MOD;
			exp = exp / 2;
		}
	}
	
	return ans;
}

int64_t g(int64_t k) {
	int64_t acc = 0;
	for (int i = 0; i < k; i++) {
		// acc = (acc + (comb[k+1][i] * f[i]) % MOD) % MOD;
		acc = mod(mod(acc) + mod(mod(comb[k+1][i]) * mod(f[i])));
	}
	return acc;
}

int64_t solve(int64_t n, int64_t k) {
	f[0] = mod(n - 1);

	// calcular funcoes anteriores
	for (int j = 1; j <= k; j++) {
		f[j] = mod(mod(mypow(mod(n), j+1) - g(j) - 1) 
				* mod(invMod(comb[j+1][j])));
	}

	return mod(f[k] - 1);
}

int main() {
	ios::sync_with_stdio(false);
	int q;
	int64_t n, k;

	for (int i = 0; i < K; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = mod(comb[i-1][j] + comb[i-1][j-1]);
		}
	}

	cin >> q;
	while (q--) {
		cin >> n >> k;

		if (n == 1) cout << 1 << endl;
		else cout << solve(n, k) << endl;
	}
	
	return 0;
}
